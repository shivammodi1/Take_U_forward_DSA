#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int firstRepeated(vector<int> &arr) {
        // code here
        unordered_map<int,int>mp;
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(mp[arr[i]]>1){
                return i+1;
            }
        }
        return -1;
        
    }
};