#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n<=1) return 1;
    return n*fact(n-1);
    // Time Complexity: O(n)
    // Space Complexity: O(n) due to recursive call stack
}

// Recursion tree for fact(4)
//                fact(4)
//              /         \
//           4 *         fact(3)
//                   /         \
//                3 *       fact(2)
//                       /         \
//                    2 *       fact(1)
//                          /         \
//                       1
// The multiplication happens as the recursive calls return 


int main(){
    int n;
    cout<<"Enter a number to find its factorial: ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is "<<fact(n)<<endl;
    return 0;
}