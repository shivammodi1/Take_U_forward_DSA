#include <bits/stdc++.h>
using namespace std;

// Longest subarray length whose  sum == k
// Longest subarray with sum K (Positives + Negatives)
// all are positive in this array
// [1 2 3 1 1 1 -3] k=3
// output-> length: 5 (longest is 3+1+1+1-3)

int subarraySum(vector<int> &nums, int k)
{
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        // int len =0;

        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            // len++;
            if (sum == k)
            {
                ans = max(ans, j - 1 + 1);
            }
        }
    }
    return ans;
}

// Method 2:
// best approach
//     prefix index
// map<int , int> mp;
//1. agar prefix ==k 
//      -> res = i+1;
//2. agar map me prefix - k -> 0 se previous tak milta hain 
//      -> res= max(res, i - mp[prefSum - k]);
//3. if (mp.find(prefSum) == mp.end())    // Store only first occurrence index of prefSum
//  mp[prefSum] = i;

int subSum(vector<int> &nums, int k){
    int preSum=0;
    int res=0;
    int n=nums.size();
    map<int , int>mp;
    for(int i=0;i<n;i++){
        preSum+=nums[i];

        if(preSum == k){
            res = i+1;
        }
        // Kya koi pehle ka prefix sum aisa tha jiska value (prefSum - k) ke barabar hai?
        else if(mp.find(preSum - k) != mp.end()){
            int len = i - mp[preSum-k]; // jahan pr presum - k wala element mila usse minus kar max le lenge
            res = max(res,len);
        }

        // check karta hai ki ye prefix sum pehle kabhi aaya tha kya
        // nhi than store that index
        if(mp.find(preSum - k) == mp.end()){
            mp[preSum] = i;
        }
    }
    return res;
}


int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    cout << subarraySum(nums, k);
}