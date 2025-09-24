#include<iostream>
int main(int c,char**v){int n=c<2?10:0;for(char*p=v[1];*p;p++)n=n*10+*p-48;int a=0,b=1;while(n--)b+=a,a=b-a;std::cout<<a;} 