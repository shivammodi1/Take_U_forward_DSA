#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int generateSum(vector<int>& arr,int mid,int t){
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i]/mid;
            if(arr[i]%mid){
                sum++;
            }
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int st = 1;
        int end = *max_element(nums.begin(),nums.end());

        int ans=-1;
        while(st<=end){
            int mid = st + (end - st)/2;

            int sum=0;
            sum = generateSum(nums,mid,threshold);

            if(sum<=threshold){
                ans = mid;
                end = mid-1;
            }else{
                st = mid+1;
            }
            
        }
        return ans;
    }
};