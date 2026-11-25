## Examining virtual memory usage in Linux based systems

Built with Clang in C++20, example usage & output below.

```
$ clang++ memory-user.cpp -std=c++20
$ ./a.out 14
14 MB of memory requested
Proccess ID: 7974
Allocated memory at: 0x7204d16a6010
8 bytes per uint64_t, 1750000 elements
Total allocated memory: 14000000 bytes
```