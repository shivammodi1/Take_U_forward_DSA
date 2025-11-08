// Search in a row wise and column wise sorted matrix
// Input: mat[][] = [[18, 21, 27],[38, 55, 67]], x = 55
// Output: true
// Explanation: 55 is present in the matrix.

// row and col wise sorted hain so 
// set pointer at top right corner
// if target is less than that element move left
// else move down


#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        int n=arr.size();
        int m=arr[0].size();
        int row=0;
        int col=m-1;
        
        while(row < n && col >= 0){
            if(arr[row][col]==x){
                return true;
            }else if(arr[row][col] > x){
                col--;
            }else{
                row++;
            }
        }
        
        return false;
        
    }
};