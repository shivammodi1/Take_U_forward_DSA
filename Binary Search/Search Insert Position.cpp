#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0,e=nums.size()-1;
        int ans=nums.size();
        while(s<=e){
            int m=s+(e-s)/2;
            if(nums[m]==target){
                
                return m;
            }else if(nums[m]<target){
               
                s=m+1;
            }else{
                 ans=m;
                e=m-1;
            }
        }
        return ans;
    }
};