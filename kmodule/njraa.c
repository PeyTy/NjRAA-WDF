// NjRAA
// Copyright (C) 2021  Oleg Petrenko
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, version 3 of the License.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <linux/init.h>
#include <linux/module.h>
#include <linux/pci.h>

#include "njraa.h"

#define NJ_DRIVER "njraa"

static struct pci_device_id nj_driver_id_table[] = {
	{ PCI_DEVICE(0x????, 0x????) },
	{ PCI_DEVICE(0x????, 0x????) },
	{0,}
};

MODULE_DEVICE_TABLE(pci, nj_driver_id_table);

static int nj_driver_probe(struct pci_dev *pdev, const struct pci_device_id *ent);
static void nj_driver_remove(struct pci_dev *pdev);

static struct pci_driver nj_driver = {
	.name = NJ_DRIVER,
	.id_table = nj_driver_id_table,
	.probe = nj_driver_probe,
	.remove = nj_driver_remove
};

struct nj_driver_priv {
	u8 __iomem *hwmem;
};


static int __init njpci_driver_init(void)
{
	return pci_register_driver(&nj_driver);
}

static void __exit njpci_driver_exit(void)
{
	pci_unregister_driver(&nj_driver);
}

void release_device(struct pci_dev *pdev)
{
	pci_release_region(pdev, pci_select_bars(pdev, IORESOURCE_MEM));
	pci_disable_device(pdev);
}

static int nj_driver_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
	int bar, err;
	u16 vendor, device;
	unsigned long mmio_start,mmio_len;
	struct nj_driver_priv *drv_priv;

	pci_read_config_word(pdev, PCI_VENDOR_ID, &vendor);
	pci_read_config_word(pdev, PCI_DEVICE_ID, &device);

	printk(KERN_INFO "Device vid: 0x%X  pid: 0x%X\n", vendor, device);

	bar = pci_select_bars(pdev, IORESOURCE_MEM);

	err = pci_enable_device_mem(pdev);

	if (err) {
		return err;
	}

	err = pci_request_region(pdev, bar, NJ_DRIVER);

	if (err) {
		pci_disable_device(pdev);
		return err;
	}

	mmio_start = pci_resource_start(pdev, 0);
	mmio_len = pci_resource_len(pdev, 0);

	drv_priv = kzalloc(sizeof(struct nj_driver_priv), GFP_KERNEL);

	if (!drv_priv) {
		release_device(pdev);
		return -ENOMEM;
	}

	drv_priv->hwmem = ioremap(mmio_start, mmio_len);

	if (!drv_priv->hwmem) {
		release_device(pdev);
		return -EIO;
	}

	pci_set_drvdata(pdev, drv_priv);

	return 0;
}

static void nj_driver_remove(struct pci_dev *pdev)
{
	struct nj_driver_priv *drv_priv = pci_get_drvdata(pdev);

	if (drv_priv) {
		if (drv_priv->hwmem) {
			iounmap(drv_priv->hwmem);
		}

		kfree(drv_priv);
	}

	release_device(pdev);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oleg Petrenko <alegorium@gmail.com>");
MODULE_DESCRIPTION("NjRAA PCI Driver");
MODULE_VERSION("0.1");

module_init(njpci_driver_init);
module_exit(njpci_driver_exit);
