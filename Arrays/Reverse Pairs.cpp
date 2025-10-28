// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].
 

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

#include<bits/stdc++.h>
using namespace std;

//method 1
// T.C -> O(n^2)
//Time Limited Exceeded
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int c = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                long long val = (long long)nums[j] * 2;
                if((long long)nums[i] > val){
                    c++;
                }
            }
        }
        return c;
    }
};
