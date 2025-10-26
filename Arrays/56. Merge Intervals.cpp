#include<bits/stdc++.h>
using namespace std;

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;

        // Pehle intervals ko sort kar lenge start time ke basis par
        // Taaki merging ek proper sequence me ho
        sort(arr.begin(), arr.end());

        // Saare intervals ko line by line check karenge
        for(int i = 0; i < n; i++){
            int st = arr[i][0]; // Current interval ka start
            int en = arr[i][1]; // Current interval ka end

            // Agar ans khaali nahi hai aur current interval ka start
            // pichle interval ke andar aa raha hai matlab overlap ho raha hai
            if(!ans.empty() && st <= ans.back()[1]){
                // Overlap ho gaya toh pichle interval ka end bada kar denge
                ans.back()[1] = max(ans.back()[1], en);
            } else {
                // Agar overlap nahi hai toh new interval ko ans me push kar denge
                ans.push_back({st, en});
            }
        }

        return ans; // Final merged intervals
    }
};
