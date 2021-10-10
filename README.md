# CFlexer

# What?
This is a C version of another engine I am making, Flexer!

# How do I compile this?
## Linux & unix based systems:
Make sure you have cmake, make, g++, GLEW, GLFW, and OpenGL installed to build this. In Debian based linux systems, this is done with the following command:
```
sudo apt install gcc cmake make libglew-dev libglfw3-dev libglm-dev mesa-utils
```
If you are on an Arch based system, I believe this is done with the following command(not really tested, so this might be wrong):
```
sudo pacman -S gcc cmake make glew glfw3 glm mesa
```

With that set up, all you have to do is just run the following command:
```
make run
```
## Windows:
I honestly have no idea how you would build this, aside from compiling with MinGW or trying to use WSL. Other than that, i'll give a fair warning that trying to compile this in windows is not going to be as easy (Though I might make a windows compatible compilation method later down the line)
