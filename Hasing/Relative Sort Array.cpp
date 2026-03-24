#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        /*
        🔷 Question:
        Given two arrays arr1 and arr2, sort arr1 such that:
        1. Elements present in arr2 should appear first in the same order as in arr2.
        2. Remaining elements (not in arr2) should be placed at the end in sorted order.

        Example:
        arr1 = [2,3,1,3,2,4,6,7,9,2,19]
        arr2 = [2,1,4,3,9,6]
        Output = [2,2,2,1,4,3,3,9,6,7,19]


        🔷 Approach:
        1. Sort arr1 → so that remaining elements are already in sorted order.
        2. Create a frequency map (mp) for arr1.
        3. Traverse arr2:
            - If element exists in map:
                → add it in result as per its frequency
                → remove it from map (to avoid duplication)
        4. Traverse arr1 again:
            - If element still exists in map:
                → add it in result
                → remove it from map
        5. Return final result.
        */

        int n = arr1.size();
        int m = arr2.size();

        // Step 1: Sort arr1
        sort(arr1.begin(), arr1.end());

        // Step 2: Frequency map
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++){
            mp[arr1[i]]++;
        }

        vector<int> ans;

        // Step 3: Place elements according to arr2
        for(int i = 0; i < m; i++){
            if(mp.find(arr2[i]) != mp.end()){
                int count = mp[arr2[i]];
                while(count--){
                    ans.push_back(arr2[i]);
                }
                // remove after use to avoid duplicates
                mp.erase(arr2[i]);
            }
        }

        // Step 4: Add remaining elements (already sorted due to arr1 sort)
        for(int i = 0; i < n; i++){
            if(mp.find(arr1[i]) != mp.end()){
                int count = mp[arr1[i]];
                while(count--){
                    ans.push_back(arr1[i]);
                }
                mp.erase(arr1[i]); // remove after processing
            }
        }

        // Step 5: Return result
        return ans;
    }
};