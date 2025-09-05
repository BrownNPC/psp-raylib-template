# Table of Contents
- [Usage](#usage)
- [Getting auto complete](#getting-auto-complete)
- [Using C++](#using-c)



# Usage

Assuming you have [pspdev](https://pspdev.github.io/installation.html)
setup.




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


## Getting auto complete

### You must use Clangd as your language server.
You can install it as an extension in VSCode.
If you use a terminal based editor, you need to configure it as a Language Server.


You need to google how to do it in your editor.
For example `vscode clangd set query driver`


The AI result is usually good.


The query driver needs to be `--query-driver=/home/<YOURUSER>/pspdev/bin/psp-gcc`



### Using C++

I do not recommend this unless you already daily drive C++.
**C23** already has many quality of life features from C++.

first delete the current build directory
```
rm -fr build
```

then, [edit your query driver](#getting-auto-complete) line to use `psp-g++` instead of `psp-gcc`
```
--query-driver=/home/<YOURUSER>/pspdev/bin/psp-g++
```




next edit `.clangd` and replace the content with the following
```
Compiler: psp-g++
Add:
  - "-std=c++23"
```

Finally run
```
psp-cmake -B build
```
now you can cd into the build directory and use `make` as usual.