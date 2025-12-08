#include <bits/stdc++.h>
using namespace std;

// Question:
// Sum of first N natural numbers

// Approach using reference variable
void sumOfNatualNumbers(int N, int &sum)
{
    if(N==0){
        return;
    }
    sum += N;
    sumOfNatualNumbers(N-1, sum);
}
// tree representation for N=4
//         sumOfNaturalNumbers(4, sum)
//        /      \
//     sum +=4   sumOfNaturalNumbers(3, sum)
//             /     \
//          sum +=3  sumOfNaturalNumbers(2, sum)
//                /    \
//             sum +=2 sumOfNaturalNumbers(1, sum)
//                   /   \
//                sum +=1 sumOfNaturalNumbers(0, sum)
//                      |
//                      return


// Alternative approach using return type
int Sum(int n){
    if(n==0){
        return 0;
    }
    return n+Sum(n-1);
}

// recursion tree for N=4
//         Sum(4)
//        /      \
//     4 +       Sum(3)
//             /     \
//          3 +     Sum(2)
//                /    \
//             2 +    Sum(1)
//                   /   \
//                1 +   Sum(0)
//                      |
//                      0

int main()
{

    int N;
    cout << "Enter a natural number: ";
    cin >> N;
    int sum = 0;
    sumOfNatualNumbers(N, sum);
    cout << "Sum of first " << N << " natural numbers is: " << sum << endl;
    return 0;
}