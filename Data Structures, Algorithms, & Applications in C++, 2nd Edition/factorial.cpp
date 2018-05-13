#include<iostream>
using namespace std;

int factorial(int n){
    if(n>1)
        return n*factorial(n-1);
    else return 1;
}

int main(){
    int a = 4;
    int fact = 0;
    fact = factorial(a);
    cout<<fact<<endl;
 
    return 0;
}