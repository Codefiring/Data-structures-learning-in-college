#include<iostream>
using namespace std;

int factorial(int n){
    int i,f=1;
    for(i=n;i>=1;i--)
    {    f=f*n;
    }
    return f;
}

int main(){
    int a = 4;
    int fact = 0;
    fact = factorial(a);
    cout<<fact<<endl;
 
    return 0;
}
