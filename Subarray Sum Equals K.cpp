#include <bits/stdc++.h>
using namespace std;

// Longest subarray length whose  sum == k
// all are positive in this array
// [1 2 3 1 1 1 3] k=3 
// output-> length: 3 (longest is 1+1+1)

int subarraySum(vector<int> &nums, int k)
{
    int ans=0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        int sum=0;
        int len =0;
        
        for(int j=i;j<n;j++){
            sum+=nums[j];
            len++;
            if(sum==k){
                ans = max(len,ans);
                break;
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    cout << subarraySum(nums,k);
}