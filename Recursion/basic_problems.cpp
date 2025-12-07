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

// Question 2.
// Print Nymber from 1 to N
// Tree structure of function calls for N=3
// PrintNumbers(3)
//    |____ PrintNumbers(2)
//              |
//              |____ PrintNumbers(1)
//                        |____ PrintNumbers(0)
//                                    |
//                                    return 
void PrintNumbers(int N){
    if(N==0){
        return;
    }
    PrintNumbers(N-1);
    cout<<N<<endl;
}

// Question 3.
// Print Number from N to 1
void PrintNumbersReverse(int N){
    if(N==0){
        return;
    }
    cout<<N<<endl;
    PrintNumbersReverse(N-1);
}

int main(){
    PrintName(5);
    PrintNumbers(5);
    PrintNumbersReverse(5);
    return 0;
}