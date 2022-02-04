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
  - Place `premake5` in a directory called `vendor/bin/premake/` along with its `LICENSE.txt`  
  (this is important for VSCode tasks)

## Why SDL2?
The book I'm following calls for a simple `putPixel()` function to create all the rendering.  
SDL2 was the first thing that popped up in a quick google search that I felt I could use to  
accomplish this. I am more than happy, and would love, for people to suggest other libraries  
and let me know the pros and cons vs SDL2. The whole point of me doing this is to learn. But,  
even if something "better" is suggested, I will not rewrite this with a different library, at  
lest, not right now.

## Why Premake?
I've messed around a bit with raw makefiles, and while they are powerful, and very cool, I feel  
that premake lets me keep my sanity. It has good enough documentation that I can find answers easily.  
It also has the ability to generate buildfiles cross platform which is something I'd like to do not  
just for this, but for future projects. Specifically I'd like to write a game engine in the future.  
I was able to link the engine into the editor with premake, but not makefiles so... premake it is.
