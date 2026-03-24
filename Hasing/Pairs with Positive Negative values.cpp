#include <bits/stdc++.h>
using namespace std;

// Given an array of integers, return all the elements having positive and negative values of a number that exists in the array.
// Note : If no such pair exists, simply return an empty array, also multiple pairs of the same number could exist and you need to put each of them in the array. Return the pairs in sorted order.

// Example:
// arr = [1,-3,2,3,6,-1,-3,3]
// output = [-1,1,-3,3,-3,3]

class Solution {
  public:
    vector<int> posNegPair(vector<int> &arr) {
        
        // map to store frequency of positive numbers
        map<int,int> pos;
        
        // map to store frequency of negative numbers (stored as absolute value)
        map<int,int> neg;
        
        vector<int> ans;

        // Step 1: Count frequency
        for(int i = 0; i < arr.size(); i++){
            
            if(arr[i] < 0){
                // store negative numbers as positive (abs value)
                neg[abs(arr[i])]++;  
            }
            else{
                // store positive numbers directly
                pos[arr[i]]++;
            }
        }

        // Step 2: Traverse negative map (sorted automatically)
        for(auto it : neg){
            int num = it.first;
            // check if corresponding positive exists
            if(pos.find(num) != pos.end()){
                
                // number of pairs possible
                int pairs = min(it.second, pos[num]);
                while(pairs--){
                    ans.push_back(-num); // negative
                    ans.push_back(num);  // positive
                }
            }
        }
        return ans;
    }
};