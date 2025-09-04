### Only for Linux / WSL.
Make sure to install the dependencies:
```
make fakeroot wget gpgme bsdtar
```
You will also need the [PSP Toolchain](https://github.com/pspdev/pspdev?tab=readme-ov-file#up-and-running) on your PC.
And the `PSPDEV` environment variable should point to it.

---

Just run
```
psp-makepkg -i 
```
