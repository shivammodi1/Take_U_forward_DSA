// ex array hain [1,2,3]
// or usme hume subarray ranges ka sum nikalna hain
// subarrays : [1] -> max - min = 0
//             [2] -> max - min = 0
//             [3] -> max - min = 0
//             [1,2] -> max - min = 2 - 1 = 1
//             [2,3] -> max - min = 3 - 2 = 1
//             [1,2,3] -> max - min = 3 - 1 = 2
// total sum = 0 + 0 + 0 + 1 + 1 + 2 = 4

#include <bits/stdc++.h>
using namespace std;

// brute force approach 
int subArrayRangeSum(vector<int>& arr){
    int n = arr.size();
    long long totalSum = 0;
    for(int i=0;i<n;i++){
        int curMax=arr[i];
        int curMin=arr[i];
        for(int j=i;j<n;j++){
            curMax = max(curMax, arr[j]);
            curMin = min(curMin, arr[j]);
            totalSum += (curMax - curMin);
        }
    }
    return totalSum;
}


//  Method 2:
// toh hum ise ayese bh dehk sakte hain:
// ans = (sum of subarray maximums) - (sum of subarray minimums)
// toh hume do cheeze nikalni hain:
// 1. sum of subarray maximums
// 2. sum of subarray minimums
// fir un dono ka difference nikal dena hain
// dono cheeze hum monotonic stack se nikal sakte hain
// jo ki humne pichle question me kiya hain 



int main(){
    return 0;
}