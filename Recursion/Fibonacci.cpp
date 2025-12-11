#include<bits/stdc++.h>
using namespace std;

int Fibo(int n){
    if(n<=1){
        return n;
    }
    return Fibo(n-1) + Fibo(n-2);
}

// Recusion Tree
//                Fibo(4)
//              /          \
//        Fibo(3)         Fibo(2)
//        /    \           /      \
//    Fibo(2)  Fibo(1)  Fibo(1)    Fibo(0)
//    /    \
// Fibo(1) Fibo(0)


int main(){
    int n;
    cin>>n;
    cout<<Fibo(n)<<endl;
    return 0;
}