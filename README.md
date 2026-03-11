## Template for using raylib to build games for PSP.
> with support for building for desktop aswell.

<img width="1551" height="463" alt="image" src="https://github.com/user-attachments/assets/a75dd010-a99a-4af6-9432-3368eb0c9a8f" />


# Table of Contents
- [Usage](#usage)
- [Running on desktop](#running-on-desktop)
- [Getting auto complete](#getting-auto-complete)



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



Speaking of code, the code is inside the `src/` folder!



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

