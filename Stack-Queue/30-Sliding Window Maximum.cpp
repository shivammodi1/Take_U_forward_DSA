#include<bits/stdc++.h>
using namespace std;


// question -> har k size ke window me maximum element find karna hai

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

class Solution {
public:
// Time Complexity: O(N)
// Space Complexity: O(K)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>d;
        // traverse till k-1 and push into deque
        for(int i=0;i<k-1;i++){
            // abb hume dq me dec order me element rakhne hain
            // agar koi bhi curr element bada hua dq me rakhe huye index se popback
            while(!d.empty() && nums[i]>nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);
        }

        // now k-1 to till n
        for(int i=k-1;i<n;i++){
             // abb hume dq me dec order me element rakhne hain
            // agar koi bhi curr element bada hua dq me rakhe huye index se popback
            while(!d.empty() && nums[i]>nums[d.back()]){
                d.pop_back();
            }
            d.push_back(i);

            // remove out-of-window index
            if(d.front()<=i-k){
                d.pop_front();
            }

            // ans is at your dq front index
            ans.push_back(nums[d.front()]);

        }

        return ans;
    }
};


// method 2 using brute force
// Time Complexity: O(N*K)
// Space Complexity: O(1)
vector<int> maxInKWindow(vector<int>&arr, int k){
    int n = arr.size();
    vector<int>res;
    for(int i=0;i<=n-k;i++){
       int mx = *max_element(arr.begin()+i, arr.begin()+i+k);
         res.push_back(mx);
    }
    return res;
}

int main(){
    Solution sol;
    vector<int>nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int>result = sol.maxSlidingWindow(nums, k);
    for(int val : result){
        cout << val << " ";
    }
    return 0;
}
