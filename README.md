# CMakeCppProjectTemplate

A CMake C++ Project Template, letting you quickly start developing a C/C++ project. Implementation details can refer to [my blog post](https://xiaobaiai.net).

# Features

- Project structure is very clear.
- With it, you can quickly start building an SDK project.
- With it, you can quickly start building an application project.
- Easy to debug and or release your software.
- Friendly logger.
- Supports cross compilation.
- Quick and easy reference to third-party projects, including source and library dependencies.
- Google c++ style.

# Prerequisites

- CMake 3.1+ installed.
- Use a C++11 compiler(C++11 is optional).

# Build & Install

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make -j
$ make install DESTDIR={your destination}
```

# Cross-compiling & Install

```bash
$ mkdir build
$ cd build
# cmake .. -DCMAKE_TOOLCHAIN_FILE=../platforms/linux/arm.himix200.cmake
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=../platforms/linux/arm.himix200.cmake -DTOOLCHAIN_ROOTDIR={your toolchain directory}/arm-himix200-linux
$ make -j
$ make install DESTDIR={your destination}
```

# TODO

- Support unit test
- Support valgrind tool
- Support threadpool
- Support static code checker
- ...

# License

[MIT](http://opensource.org/licenses/MIT)

Copyright (c) 2020-present, Yiming(Ethan)
