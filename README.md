# GraphicsFromScratch
A raytracer and rasterizer from following "Computer Graphics From Scratch" by Gabriel Gambetta.

## VS Code
I used VS Code to write this and recommend it to anyone downloading it as I will continue to create tooling for VS Code as I progress.
You'll have access to this in the form of the `.vscode` folder.

## Supported Platforms
I would like to get `premake5.lua` to a point where it can create porjects for each platform, but for now it just supports Linux.
- Linux

## Running the Program
1. The renderers in this project utilize SDL2 to create windows, draw on the screen, etc. so you will need to install that.
```
apt-get install libsdl2-dev
```
2. The makefiles are included and need to be run.
```
make
```
3. After the program is built, you can run it by executing the `RayTracer` program in `/bin/linux-x86_64/RayTracer/`
```
./bin/linux-x86_64/RayTracer/RayTracer
```
If you see a red, green, and blue sphere pop up in a small window, you've set it up correctly.
Behavior will change as I develop.

## Developing the Program
### Dev Dependencies
- SDL2
  ```
  apt-get install libsdl2-dev
  ```
- Premake5
  - Download `premake5` from [here](https://premake.github.io/download)
  - Place in a directory called `vendor/bin/premake/premake5`
    (this is important for VSCode tasks)