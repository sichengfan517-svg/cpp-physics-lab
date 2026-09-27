cmake_minimum_required(VERSION 3.16)
project(cpp_physics_lab LANGUAGES CXX)

add_executable(cpp_physics_lab src/main.cpp)
target_compile_features(cpp_physics_lab PRIVATE cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  target_compile_options(cpp_physics_lab PRIVATE -Wall -Wextra -Wpedantic)
endif()
enable_testing()
add_test(NAME smoke COMMAND cpp_physics_lab)
set_tests_properties(smoke PROPERTIES PASS_REGULAR_EXPRESSION "cpp-physics-lab ready")
