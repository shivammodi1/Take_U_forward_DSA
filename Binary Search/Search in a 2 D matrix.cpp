#include<bits/stdc++.h>
using namespace std;

// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        // your code here
        int st = 0;
        int end = arr[0].size() * arr.size() - 1;
        
        while(st<=end){
            ///  mid as a index
            int mid = st + (end-st)/2;
         // this is fow row major order
            int row = mid/arr[0].size(); // for finding rowIndex = index/col_size
            int col = mid%arr[0].size(); // fir colIndex = index%col_size
            
            if(arr[row][col]==x){
                return true;
            }else if(arr[row][col]>x){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return false;
    }
};