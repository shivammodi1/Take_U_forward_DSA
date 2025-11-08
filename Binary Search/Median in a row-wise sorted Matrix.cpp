#include <bits/stdc++.h>
using namespace std;

// method 1: using sorting 
class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(mat[i][j]);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans[ans.size()/2];
        
    
    }
};
// time complexity: O(n*m log(n*m))
// space complexity: O(n*m)


// method 2: using binary search
