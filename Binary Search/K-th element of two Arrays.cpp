#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int n1=a.size();
        int n2=b.size();
        
        vector<int>ans;
        
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(a[i]<b[j]){
                ans.push_back(a[i++]);
            }else{
                ans.push_back(b[j++]);
            }
        }
        
        while (i < n1)
            ans.push_back(a[i++]);
        while (j < n2)
            ans.push_back(b[j++]);
            
        return ans[k-1];
    }
};