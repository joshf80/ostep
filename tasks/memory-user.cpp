#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <cstdint>
#include <unistd.h>

int main(int argc, char* argv[]) {
    const auto* memory = argv[1];
    if(!std::is_integral_v<decltype(*memory)>) { std::runtime_error("Incorrect argument syntax"); }

    std::cout << *memory << " MB of memory requested" << std::endl;
    const std::size_t sizeOfMemory = static_cast<std::size_t>(*memory - '0') * 1'000'000;

    std::cout << "Proccess ID: " << getpid() << std::endl;
    uint64_t* ptr = new uint64_t[sizeOfMemory / sizeof(uint64_t)];
    std::cout << "Allocated memory at: " << static_cast<void*>(ptr) << std::endl;
    std::cout << sizeof(uint64_t) << " bytes per uint64_t" << std::endl;
    std::cout << "Total allocated memory: " << sizeOfMemory << " bytes" << std::endl;
    int x = 0;
    std::cin >> x;
    delete[] ptr;
}
