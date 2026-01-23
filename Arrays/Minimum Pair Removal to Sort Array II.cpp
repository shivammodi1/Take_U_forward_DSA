#include<istream>/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSorted(vector<long long>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]>nums[i]){
                return 0;
            }
        }
        return 1;
    }
    int minimumPairRemoval(vector<int>& nums) {
        vector<long long> arr(nums.begin(),nums.end());
        int n=arr.size();
        
        // if nums already sorted
        if(isSorted(arr)){
            return 0;
        }

        // if n==2 and not sorted
        if(n==2 && !isSorted(arr)){
            return 1;
        }

        int count=0;
        while(!isSorted(arr)){
            int n=arr.size();
            long long minSum = LLONG_MAX;
            long long sum = 0;
            int index=-1;
            for(int i=0;i<n-1;i++){
                sum = (long long)arr[i] + arr[i+1];
                if(sum<minSum){
                    minSum=sum;
                    index=i;
                }
            }

            // replace with minSum at index
            arr[index] = minSum;
            // erase index+1 from nums
            arr.erase(arr.begin()+index+1);
            // inc count
            count++;
        }
        return count;
    }
};



// 674 / 681 testcases passed