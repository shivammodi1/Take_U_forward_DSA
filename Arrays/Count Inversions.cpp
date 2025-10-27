// Given an array of integers arr[]. You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
#include<bits/stdc++.h>
using namespace std;

// Method 1
// T.C -> O(N^2)
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int N = arr.size();
        int count = 0;
    for(int i = 0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]>arr[j] && i<j) {
                count++;
            }
        }
    }
    return count;
    }
};
