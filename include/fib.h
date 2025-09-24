#pragma once
#include <cstdint>
#include <string>
#include <algorithm>

// Iterative Fibonacci (O(n)) returning F(n) for n<=93 safely in 64-bit unsigned.
inline std::uint64_t fib(std::uint32_t n) {
    std::uint64_t a=0,b=1; while(n--) { b+=a; a=b-a; } return a;
}

// Return Fibonacci(n) as a decimal string for arbitrary n (simple O(n^2) string-based addition)
inline std::string fib_str(unsigned n){
    if(n==0) return "0"; if(n==1) return "1"; std::string a="0",b="1";for(unsigned i=2;i<=n;++i){
        std::string s; s.reserve(b.size()+1);
        int carry=0; auto it1=a.rbegin(), it2=b.rbegin();
        while(it1!=a.rend()||it2!=b.rend()||carry){
            int d=carry; if(it1!=a.rend()) d+=*it1++-'0'; if(it2!=b.rend()) d+=*it2++-'0';
            s.push_back(char('0'+(d%10))); carry=d/10;
        }
        std::reverse(s.begin(),s.end()); a.swap(b); b.swap(s);
    } return b;
}
