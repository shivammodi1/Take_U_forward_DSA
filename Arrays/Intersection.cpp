#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        int i=0,j=0;
        set<int>ans;
        while(i<n && j<m){
            if(nums1[i]<nums2[j]){
                i++;
            }else if(nums1[i] > nums2[j]){
                j++;
            }else{
                ans.insert(nums1[i++]);
                j++;
            }
        }
    vector<int> ans1(ans.begin(),ans.end());
        return ans1;
    }
};