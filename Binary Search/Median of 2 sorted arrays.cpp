#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans; // merged array
        int i = 0, j = 0;
        int n1 = nums1.size();
        int n2 = nums2.size();

        // Step 1: Merge both sorted arrays
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }

        // Add remaining elements (if any)
        while (i < n1)
            ans.push_back(nums1[i++]);
        while (j < n2)
            ans.push_back(nums2[j++]);
        
        
        double med;
        int n = n1+n2;
        if(n%2==1){
            //odd size
             med = double(ans[n/2]);
        }
        else {
            //even size
            med = (ans[n / 2 - 1] + ans[n / 2]) / 2.0;
        }
        return med;
    }
};