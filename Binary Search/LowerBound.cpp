// LowerBound -> smallest index such that arr[mid] > = target

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans=n;

    while(low<=high){
        int mid = low + (high-low)/2;

        // if target is found or greater than store or furter check for better ans
        if(arr[mid]>=target){
            ans=mid;
            high=mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
    }
};

int main()
{
}