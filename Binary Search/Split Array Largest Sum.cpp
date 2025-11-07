#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // 'st' represents the minimum possible largest sum of subarrays.
        // It should be at least the largest element in the array.
        int st = *max_element(arr.begin(), arr.end());
        
        // 'end' represents the maximum possible largest sum (when all elements are in one subarray).
        int end = 0;
        for(int i = 0; i < n; i++){
            end += arr[i];
        }
        
        int ans; // to store the final minimized largest sum
        
        // Binary Search between 'st' and 'end'
        while(st <= end){
            
            // mid is the possible largest subarray sum we are testing
            int mid = st + (end - st) / 2;
            
            int sum = 0;     // current subarray sum
            int count = 1;   // count how many subarrays are formed
            
            // Check how many subarrays are needed if we limit each to sum <= mid
            for(int i = 0; i < n; i++){
                sum += arr[i];
                
                // if adding this element exceeds 'mid', start a new subarray
                if(sum > mid){
                    count++;
                    sum = arr[i]; // start new subarray from this element
                }
            }
            
            // If number of subarrays formed <= k, it means 'mid' is a valid maximum sum
            // Try to minimize it by moving towards smaller values
            if(count <= k){
                ans = mid;
                end = mid - 1;
            }
            // Else, we need to allow a larger maximum sum, so move right
            else {
                st = mid + 1;
            }
        }
        
        // 'ans' holds the minimized largest sum after binary search
        return ans;
    }
};
