// Example 1:

// Input: grid = [[1,3],[2,2]]
// Output: [2,4]
// Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int total = n * n;
        
        unordered_map<int, int> freq;
        
        // Fill frequency map
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                freq[grid[i][j]]++;
            }
        }

        int repeated = -1, missing = -1;

        // Check each number from 1 to n*n
        for(int i = 1; i <= total; i++){
            if(freq[i] == 2) repeated = i;
            if(freq[i] == 0) missing = i;
        }
        
        return {repeated, missing};
    }
};
