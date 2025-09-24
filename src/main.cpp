#include <iostream>
long long f(long long n){return n<2?n:f(n-1)+f(n-2);} // naive recursive (few lines)
int main(int argc,char** argv){long long n= (argc>1? std::atoll(argv[1]):10);std::cout<<f(n)<<"\n";}
