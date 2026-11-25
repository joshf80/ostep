#include <iostream>
#include <chrono>

auto measure() {
    constexpr auto pages = 2;
    constexpr auto multiplier = 2;
    constexpr auto stride = 4096 / sizeof(int);;
    constexpr auto iterations = 1'000;
    volatile int sink = 0;

    using namespace std::chrono;

    for(int currPages = pages; currPages <= 4096; currPages *= multiplier) {
        const auto elements = currPages * 4096 / sizeof(int);
        auto* arr = new int[elements]{}; 

        auto start = steady_clock::now();
        for(int it = 0; it < iterations * 4096 ; ++it) {
            for(int i = 0; i < elements; i += stride) {
                arr[i] += sink; 
            }
        }
        auto end = steady_clock::now();
        delete[] arr;

        const double elapsedNs = duration<double, std::nano>(end - start).count();
        const double accessCount = static_cast<double>(iterations) * 4096 * currPages;

        std::cout << "Pages worth of data measured: " << currPages << std::endl;
        std::cout << "Average time per access: " << elapsedNs / accessCount << "ns" << std::endl;
    }
}


int main() {
    measure();
}