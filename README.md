# NjRAA-WDF

What I'm doing here is a GPU driver for Windows 10 as a prototype for future graphics stack of the [@GreenteaOS](https://github.com/GreenteaOS)

#### Aim

To support GCN 1.0+ GPUs.

#### Supported GPUs

- [ ] **`AMD Radeon R7 200 Series`** `PCI\VEN_1002&DEV_6610&REV_00`

#### Step by step

- [ ] Create IOCTL API to control driver from userspace
- [ ] Init GPU engine and setup command buffer
- [ ] Mode setting
- [ ] Draw anything on screen

#### Limitations

This is *not* intended to become a Windows WDDM driver.

Only fullscreen applications supported, no desktop GUI!
Use only for secondary GPU with extra screen
(or use extra inputs and switch dynamically).

#### Build

Use `Release` build of `x64` target only.

#### License

GNU LESSER GENERAL PUBLIC LICENSE Version 3
