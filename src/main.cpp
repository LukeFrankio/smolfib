#include<iostream>
int f(int n){return n<2?n:f(n-1)+f(n-2);}int main(int c,char**v){int n=10;if(c>1){n=0;for(char*p=v[1];*p;p++)n=n*10+*p-48;}std::cout<<f(n);} 
