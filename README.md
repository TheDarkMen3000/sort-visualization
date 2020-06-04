# Sort-Visualization
This is a small tool to visually represent the working of sorting algorithms.
OpenGL is used to visualize the sorting of an array represented by bars with different heights.

The Project is planned to support sorting algorithms written in Lua. With this approach its easy to add new algorithms.

## Dependencies
The application uses the following dependencies.

- [GLFW](https://github.com/glfw/glfw)
- [GLEW](https://github.com/nigels-com/glew) with CMake support from [here](https://github.com/Perlmint/glew-cmake)
- [Lua](https://github.com/LuaDist/lua)
- [sol2](https://github.com/ThePhD/sol2)

All these dependencies are added through git submodules. In order to clone this repository the clone option '--recursive' is recommended. Copy the following command to clone this repository to your device.

```
git clone --recursive https://github.com/TheDarkMen3000/sort-visualization
```

## Building
To build this application you need to install CMake. After the installation run the following commands:

```
mkdir build
cd build
cmake ..
```
Look into the documentation of CMake [here](https://cmake.org/documentation/) to find further information.