#include <bits/stdc++.h>
using namespace std;


// Subarray with sum 0 
// array = [1, -1, 2, 3, -2]
// find if there is a subarray with sum 0


// Approach 1: Brute Force O(N^2)
bool subArraySumZero(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        int sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            if(sum==0){
                return true;
            }
        }
    }
    return false;
}

// Approach 2: Hashing O(N)
// We are using Hasing and Prefix sum
// yahan preSum1 ko store karege hash map me
// aur jab preSum2 milega to check karege ki preSum1 aur preSum2 same hai ya nahi
// preSum1 == preSum2 => subarray sum 0

// Example: arr = [1, -1, 2, 3, -2] 
// preSum = 0
// i=0: preSum = 1, mp[1] = 0
// i=1: preSum = 0, return true (subarray [1, -1])


bool subArraySumZero(vector<int>&arr){
    int n=arr.size();
    unordered_map<int,int> mp; // preSum -> index
    int preSum=0;
    for(int i=0;i<n;i++){
        preSum+=arr[i];
        // check preSum is 0 or not 
        // agar 0 nhi toh find preSum in map
        if(preSum==0 || mp.find(preSum)!=mp.end()){
            return true;
        }
        mp[preSum]=i; // store preSum in map
    }
    return false;
}