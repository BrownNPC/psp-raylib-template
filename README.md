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
```

Now to setup a build directory run
```
psp-cmake -B build
```

then `cd` into the build directory
```
cd build
```

to build/rebuild your project type `make` which will produce an `EBOOT.PBP`.


You can run that inside PPSSPP by just dragging it in.

Also,
change your game's name inside `CMakeLists.txt`
and `main.cpp`
