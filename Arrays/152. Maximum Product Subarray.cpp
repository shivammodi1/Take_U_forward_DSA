#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];

        int curr = 1;

        // Left to right
        for(int i = 0; i < n; i++) {
            curr *= nums[i];
            ans = max(ans, curr);
            if(curr == 0) curr = 1;
        }

        curr = 1;

        // Right to left
        for(int i = n - 1; i >= 0; i--) {
            curr *= nums[i];
            ans = max(ans, curr);
            if(curr == 0) curr = 1;
        }

        return ans;
    }
};
