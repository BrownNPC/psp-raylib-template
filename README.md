# Usage

Assuming you have [pspdev](https://github.com/pspdev/pspdev/?tab=readme-ov-file#up-and-running)
setup.



And the following dependencies:
```
git make cmake fakeroot wget gpgme bsdtar
```

Just run this once
```
psp-pacman -Sy raylib
psp-cmake -B build
cd build
```

then to build your project type `make` which will produce an `EBOOT.PBP`.


You can run that inside PPSSPP by just dragging it in.

Also,
change your game's name inside `CMakeLists.txt`
and `main.cpp`
