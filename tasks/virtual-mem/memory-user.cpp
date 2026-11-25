#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <unistd.h>

int main(int argc, char* argv[]) {
    const auto* memory = argv[1];
    auto total = 0;

    for(const char* c = memory; *c != '\0'; ++c) {
        if(!std::isdigit(*c)) { std::runtime_error("Incorrect argument syntax"); }
        total *= 10;
        total += *c - '0';
    }

    const std::size_t sizeOfMemory = static_cast<std::size_t>(total) * 1'000'000;
    uint64_t* ptr = new uint64_t[sizeOfMemory / sizeof(uint64_t)];

    
    std::cout << total << " MB of memory requested" << std::endl;
    std::cout << "Proccess ID: " << getpid() << std::endl;
    std::cout << "Allocated memory at: " << static_cast<void*>(ptr) << std::endl;
    std::cout << sizeof(uint64_t) << " bytes per uint64_t, " << sizeOfMemory / sizeof(uint64_t) << " elements" << std::endl;
    std::cout << "Total allocated memory: " << sizeOfMemory << " bytes" << std::endl;
    
    auto x = 0;
    std::cin >> x;
    
    delete[] ptr;
}
