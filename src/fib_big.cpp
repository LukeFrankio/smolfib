#include <iostream>
#include "fib.h"
int main(int c,char**v){unsigned n= (c>1? (unsigned)std::strtoul(v[1],nullptr,10):100);auto s=fib_str(n);std::cout<<s<<"\n";}
