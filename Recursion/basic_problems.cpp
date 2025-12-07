#include<bits/stdc++.h>
using namespace std;

// Question 1. 
// Print the name for 5 times
void PrintName(int N){
    if(N==0){
        return;
    }
    cout<<"Shivam Modi"<<endl;
    PrintName(N-1);
}

int main(){
    PrintName(5);
}