#pragma once
#include <cstdint>

// Iterative Fibonacci (O(n)) returning F(n) for n<=93 safely in 64-bit unsigned.
inline std::uint64_t fib(std::uint32_t n) {
    std::uint64_t a=0,b=1; while(n--) { b+=a; a=b-a; } return a;
}
