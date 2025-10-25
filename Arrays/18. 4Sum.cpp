#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int st=j+1;
                int end=n-1;
                while(st<end){
                    long long sum = (long long)arr[i]+arr[j]+arr[st]+arr[end];
                    // if sum==target than store directly in set for uniqueness
                    if(sum==target){
                        vector<int>tmp = {arr[i],arr[j],arr[st],arr[end]};
                        s.insert(tmp);
                        st++,end--;
                    }else if(sum<target){
                        // lesser than 0 move forward for making near 0 or equal 0
                        st++;
                    }else{
                        // Othereise more back if more than 0
                        end--;
                    }
                }
            }
        }
        vector<vector<int>>res(s.begin(),s.end());
        return res;
    }
};