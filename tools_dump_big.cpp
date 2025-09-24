#include <iostream>
#include "include/fib.h"
int main(){auto f500=fib_str(500);auto f1000=fib_str(1000);std::cout<<"F500 prefix5="<<f500.substr(0,5)<<" suffix5="<<f500.substr(f500.size()-5)<<"\n";std::cout<<"F1000 prefix5="<<f1000.substr(0,5)<<" suffix5="<<f1000.substr(f1000.size()-5)<<"\n";}
