(gdb) catch throw
Catchpoint 1 (throw)
(gdb) run
Starting program: /home/fansicheng/dev/cpp-physics-lab/build/array_bug
[Thread debugging using libthread_db enabled]
Using host libthread_db library "/lib/x86_64-linux-gnu/libthread_db.so.1".

Catchpoint 1 (exception thrown), 0x00007ffff7cae4a1 in __cxa_throw () from /lib/x86_64-linux-gnu/libstdc++.so.6
(gdb) bt
#0  0x00007ffff7cae4a1 in __cxa_throw () from /lib/x86_64-linux-gnu/libstdc++.so.6
#1  0x00007ffff7ca54cd in ?? () from /lib/x86_64-linux-gnu/libstdc++.so.6
#2  0x0000555555555797 in std::vector<int, std::allocator<int> >::_M_range_check (this=0x7fffffffddd0, __n=3)
    at /usr/include/c++/11/bits/stl_vector.h:1073
#3  0x00005555555554f9 in std::vector<int, std::allocator<int> >::at (this=0x7fffffffddd0, __n=3)
    at /usr/include/c++/11/bits/stl_vector.h:1112
#4  0x00005555555552e5 in main () at src/array_bug.cpp:7
(gdb) frame 4
#4  0x00005555555552e5 in main () at src/array_bug.cpp:7
7               (void)values.at(i);
(gdb) list
2       #include <vector>
3
4       int main() {
5           const std::vector<int> values{10, 20, 30};
6           for (std::size_t i = 0; i <= values.size(); ++i) {
7               (void)values.at(i);
8           }
9       }
(gdb) print i
$1 = 3
(gdb) print values.size()
$2 = 3
(gdb) nano array_bug.cpp
Undefined command: "nano".  Try "help".

fansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab$ nano array_bug.cpp
fansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab$ cd src
fansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab/src$ nano array_bug.cpp
ansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab/src$ cd ..
fansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab$ g++ -std=c++17 -g -O0 -Wall -Wextra -Wpedantic src/array_bug.cpp -o build/array_bug
fansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab$ ./build/array_bug
fansicheng@LAPTOP-FAN:~/dev/cpp-physics-lab$ echo $?
0
