## 项目目的

这是一个用于练习 C++、CMake、GDB 和 Git 基础流程的小型项目。

当前程序用于验证以下开发闭环：

1. 使用 C++17 编写程序。
2. 使用 CMake 配置并编译工程。
3. 使用 CTest 执行冒烟测试。
4. 使用 GDB 定位简单的数组越界问题。
5. 使用 Git 记录代码和文档修改。

## 开发环境

本项目目前在 WSL2 Ubuntu 环境中开发和验证。

编译器、CMake、Git、GDB 和操作系统的具体版本见：

- [开发环境记录](docs/environment.md)


## 目录说明

```text
.
├── CMakeLists.txt          # CMake 工程配置和 CTest 冒烟测试
├── README.md               # 项目说明和使用方法
├── .clang-format           # C++ 代码格式化规则
├── src/
│   ├── main.cpp            # 主程序
│   └── array_bug.cpp       # GDB 数组边界调试练习
├── docs/
│   ├── environment.md      # 开发环境和工具版本
│   └── debugging-w01.md    # W01 调试过程记录
├── notes/
│   └── git-basics.md       # Git 基础概念笔记
└── build/                  # CMake 构建产物，不提交到 Git
```










## 手动编译
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/main.cpp -o build/manual_hello
./build/manual_hello


##CMake构建
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/cpp_physics_lab

## CTest 测试

先完成 CMake 配置和构建，然后执行：

```bash
ctest --test-dir build -N
ctest --test-dir build --output-on-failure
## 独立调试练习

`src/array_bug.cpp` 是独立的 GDB 调试示例，不属于主程序。编译和运行方法：

```bash
g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic src/array_bug.cpp -o build/array_bug
./build/array_bug
echo $?
```

修复后的程序应正常退出，`echo $?` 应输出：

```text
0
