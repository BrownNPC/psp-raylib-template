# Table of Contents
- [Usage](#usage)
- [Getting auto complete](#getting-auto-complete)
- [Using C++](#using-c)



# Usage

Assuming you have [pspdev](https://pspdev.github.io/installation.html) setup for your OS.


Just run this once in your terminal.
```
cc -o nob nob.c
```

Now prepare the project.
```
./nob prepare-psp
```

then build it.
```
./nob build
```

to build/rebuild your project type `make` which will produce an `EBOOT.PBP`.


You can run that inside PPSSPP by just dragging it in.

Also,
change your game's name inside `CMakeLists.txt`
and `main.cpp`


## Getting auto complete

### You must use Clangd as your language server.

You can install it as an extension in VSCode.
If you use a terminal based editor, you need to configure it as a Language Server.

