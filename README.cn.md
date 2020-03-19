[English](./README.md) | 简体中文

# CMakeCppProjectTemplate

一个CMake C++项目模板，可以让你快速的开始一个C++项目。具体的实现细节可以参见[我的博文](https://mp.weixin.qq.com/s/mVnx3oua21De7zOtG1Mhvw).

# 特性

- 清晰的工程结构。
- 可以快速开始构建一个SDK项目。
- 可以快速开始构建一个App项目。
- 很方便的编译出调试/发布版本。
- 内置友好的日志记录器。
- 支持交叉编译配置。
- 方便快速的导入第三方库，支持源码依赖和库依赖。
- 谷歌C++编码规范。

# 环境要求

- CMake 3.1+ 已安装。
- 能够支持C++11的编译器(4.8+)

# 编译和安装

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make -j
$ make install DESTDIR={your destination}
```

# 交叉编译和安装

```bash
$ mkdir build
$ cd build
# cmake .. -DCMAKE_TOOLCHAIN_FILE=../platforms/linux/arm.himix200.cmake
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=../platforms/linux/arm.himix200.cmake -DTOOLCHAIN_ROOTDIR={your toolchain directory}/arm-himix200-linux
$ make -j
$ make install DESTDIR={your destination}
```

# TODO

- 支持单元测试
- 支持内存泄露检查
- 支持线程池
- 支持静态代码检查
- ......

# 授权

[MIT](http://opensource.org/licenses/MIT)

Copyright (c) 2020-present, Yiming(Ethan)
