## Examining virtual memory usage in Linux based systems

### Built with Clang in C++20, example usage & output below.

```
$ clang++ memory-user.cpp -std=c++20
$ ./a.out 10
10 MB of memory requested
Proccess ID: 13054
Allocated memory at: 0x7cd84b476010
8 bytes per uint64_t, 1250000 elements
Total allocated memory: 10000000 bytes
```

### Onto the more interesting:
```
$ pmap -x 13054
Address           Kbytes     RSS   Dirty Mode  Mapping
...
00007cd84b476000    9768       4       4 rw---   [ anon ] // Row of interest
...
```
Now running with the more detailed flag we can see:
```
$ pmap -X 13054
 Address          Perm      Offset  Device  Inode Size  Rss Pss Pss_Dirty Referenced Anonymous   Mapping
5826f62d7000 rw-p 00000000   00:00      0     132    8   8         8          8                 8                     [heap]
7cd84b476000 rw-p 00000000   00:00      0     9768  4   4         4          4                4
```
Layout simplified for sake of fitting it in.

### Cool Note
Rss shows we are only bringing in 4kb worth of pages or equivocally 1 page, since we aren't writing to array, the 10mb we allocated is not yet residing in our RAM.