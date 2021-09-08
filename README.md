# NjRAA Work-in-progress Driver Foundation

`[nee-jee-ray]`

What I'm doing here is a GPU driver for Linux as a prototype for future graphics stack of the [@GreenteaOS](https://github.com/GreenteaOS)

![NjRAA Logo](njraa.png?raw=true)

#### Aim

To support AMD GCN 1.0+ GPUs. And Intel/Nvidia ones that conform to
[Resource binding Tier 3 and Resource heap Tier 2](https://en.wikipedia.org/wiki/Feature_levels_in_Direct3D#Support_matrix).

This project is a part of future Driver Reusability Initiative (to be announced).

#### Supported GPUs

- [ ] [**`AMD Radeon R7 200 Series`**](https://www.techpowerup.com/gpu-specs/radeon-r7-250.c2459) `PCI\VEN_1002&DEV_6610&REV_00` **`Oland GFX6 (gfx601)`**
- [ ] [**`Radeon RX 5500 XT`**](https://www.techpowerup.com/gpu-specs/radeon-rx-5500-xt.c3468) `PCI\VEN_1002&DEV_7340&REV_C5` **`Navi GFX10 (gfx1012)`**

Later GCN/RDNA GPUs will reuse huge parts of GCN 1.0 code.

- [ ] [**`Intel(R) HD Graphics 500`**](https://en.wikipedia.org/wiki/Intel_Graphics_Technology#Apollo_Lake) `PCI\VEN_8086&DEV_5A85&REV_0B` **`Gen. 9 (Skylake)`**
- [ ] [**`Intel(R) UHD Graphics 630`**](https://en.wikipedia.org/wiki/Intel_Graphics_Technology#Kaby_Lake_Refresh_/_Amber_Lake_/_Coffee_Lake_/_Coffee_Lake_Refresh_/_Whiskey_Lake_/_Comet_Lake) `PCI\VEN_8086&DEV_TBA&REV_TBA` **`Gen. 9.5 (Kaby Lake)`**
- [ ] [**`Intel(R) UHD Graphics 750`**](https://en.wikipedia.org/wiki/Intel_Graphics_Technology#Twelfth_generation_(Gen12)) `PCI\VEN_8086&DEV_TBA&REV_TBA` **`Gen. 12 (Rocket Lake-S)`**
- [ ] [**`Intel(R) Iris(R) Xe Graphics`**](https://en.wikipedia.org/wiki/Intel_Graphics_Technology#Twelfth_generation_(Gen12)) `PCI\VEN_8086&DEV_TBA&REV_TBA` **`G7 Gen. 12 (Tiger Lake-U)`**

#### Step by step

- [ ] Create IOCTL API to control driver from userspace
- [ ] Init GPU engine and setup command buffer
- [ ] Mode setting
- [ ] Draw anything on screen

#### Limitations

Only fullscreen applications supported, no desktop GUI!
Use only for secondary GPU with extra screen
(or use extra inputs and switch dynamically).

#### Build

Use `make` to build `kmodule` kernel mode driver.

#### License

GNU LESSER GENERAL PUBLIC LICENSE Version 3
