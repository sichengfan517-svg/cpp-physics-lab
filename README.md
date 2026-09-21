
## 手动编译
mkdir -p build
g++ -std=c++17 -Wall -Wextra -Wpedantic src/main.cpp -o build/manual_hello
./build/manual_hello


##CMake构建
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/cpp_physics_lab

