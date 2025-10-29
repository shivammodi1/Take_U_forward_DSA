#include<bits/stdc++.h>
using namespace std;

// ✅ Workflow: Maximum Product Subarray using Your Logic
// Step 1: Left to Right Traversal

// Jis tarah tum pehle array traverse kar rahe the:

// Ek running product curr banate ho

// Har element multiply karte ho

// Maximum ans update karte ho

// Zero aaye to reset karte ho

// Purpose:
// Agar best product starting se ya left side se ban raha ho, to ye pakad lega.

// 📌 Example:
// [2, 3, -2, 4]
// Forward pass hi sahi answer pakad leta hai.

// Problem

// Agar somewhere beech me product negative ho gaya
// to tum usko reset karke us future wale positive result ko miss kar doge.

// Step 2: Right to Left Traversal

// Ab hum array ulta traverse karte hain:

// Again, running product multiply

// Max update

// Zero par reset

// Purpose:
// Agar best product end se ya right side se ban raha ho, to ye usko pakad lega.

// 📌 Example:
// [2, -5, -2, -4, 3]
// Right-to-left pass hi 24 ko pakadta hai.
// Left pass fail ho jata.

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
