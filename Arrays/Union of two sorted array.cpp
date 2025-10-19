#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> ans;
        int n = a.size();
        int m = b.size();
        
        for(int i=0;i<n;i++){
            if(ans.empty() || ans.back() != a[i]){
                ans.push_back(a[i]);
            }
        }
        for(int i=0;i<m;i++){
            if(ans.empty() || ans.back() != b[i]){
                ans.push_back(b[i]);
            }
        }
        
        vector<int>res;
        sort(ans.begin(), ans.end());
        res.push_back(ans[0]); // Add the first element

        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] != ans[i - 1]) {
                res.push_back(ans[i]);
            }
        }

        return res;
        
        // int i = 0, j = 0;
        
        // while(i < n && j < m){
        //     if(a[i] < b[j]){
        //         if(ans.empty() || ans.back() != a[i]) // checking duplicates
        //             ans.push_back(a[i]);
        //         i++;
        //     } else if(a[i] > b[j]){
        //         if(ans.empty() || ans.back() != b[j])
        //             ans.push_back(b[j]);
        //         j++;
        //     } else {
        //         if(ans.empty() || ans.back() != a[i])
        //             ans.push_back(a[i]);
        //         i++;
        //         j++;
        //     }
        // }

        // while(i < n){
        //     if(ans.empty() || ans.back() != a[i])
        //         ans.push_back(a[i]);
        //     i++;
        // }

        // while(j < m){
        //     if(ans.empty() || ans.back() != b[j])
        //         ans.push_back(b[j]);
        //     j++;
        // }

        // return ans;
    }
};