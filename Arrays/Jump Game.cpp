#include<bits/stdc++.h>
using namespace std;

// ------------------------------------------------------------------------------------------------------------------------------------------
// question : 
//Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.
// -----------------------------------------------------------------------------------------------------------------------------------------
// Example:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
//------------------------------------------------------------------------------------------------------------------------------------------
// Approach:
// step 1: set goal to last index
// step 2: iterate from second last index to first index
// step 3: if current index + nums[current index] >= goal, update goal to current index
// step 4: finally check if goal is 0, if yes return true else false
//------------------------------------------------------------------------------------------------------------------------------------------

bool canJump(vector<int>& nums){
    int n = nums.size();
    int goal = n-1;
    for(int i=n-2; i>=0; i--){
        if(i + nums[i] >= goal){
            goal = i;
        }
    }
    if(goal == 0){
        return true;
    }
    return false;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    bool result = canJump(nums);
    cout << "Can reach the last index: " << (result ? "true" : "false") << endl;
    return 0;
}