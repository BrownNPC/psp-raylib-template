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

Then build it.
```
./nob build
```
Inside `dist/psp` There would be EBOOT.PBP, run it using PPSSPP.



Do `./nob build` every time you make a change in the code.



# Running on desktop

```
./nob prepare-desktop
```

OR to cross-compile for Windows

```
./nob prepare-desktop-win
```

then build it!

```
./nob build
```

Then launch it using
```
./nob run
```
OR
```
./nob run-win
```

## Getting auto complete

### You must use Clangd as your language server.

You can install it as an extension in VSCode.
If you use a terminal based editor, you need to configure it as a Language Server.

