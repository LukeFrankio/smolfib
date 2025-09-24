# Minimal Fibonacci (C++)

Single-file recursive Fibonacci calculator written in as few lines as practical.

## Build (CMake)

```bash
cmake -S . -B build
cmake --build build --config Release
./build/fib 10
```

## One-liner compile (no CMake)

```bash
g++ -std=c++17 -O2 -o fib src/main.cpp && ./fib 10
```

Pass an integer argument (defaults to 10).

Note: This is the naive exponential-time recursion for brevity, not performance.
