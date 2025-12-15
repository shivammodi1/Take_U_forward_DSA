#include<bits/stdc++.h>
using namespace std;

vector<int> subsetSums(vector<int>& arr){

}

int main(){
    return 0;
}

// Input: arr[] = [2, 3]
// Output: [0, 2, 3, 5]
// Explanation: 
// When no elements are taken then Sum = 0. 
// When only 2 is taken then Sum = 2. 
// When only 3 is taken then Sum = 3. 
// When elements 2 and 3 are taken then Sum = 2+3 = 5.

// Recursion Tree
//                 [2 , 3] , sum = 0
//               /                     \
//           include 2 , sum = 2        exclude 2 , sum = 0
//          /            \                 /             \
//   include 3 , sum=5   exclude 3,sum=2   include 3,sum=3   exclude 3,sum=0
// Final Sums = [0, 2, 3, 5]