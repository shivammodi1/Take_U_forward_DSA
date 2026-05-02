// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11

// Algorithm:
// 1. Calculate the total sum of the array.
// 2. Initialize a variable leftSum to 0.
// 3. Iterate through the array, for each index i:
//      a. calculate the right sum as totalSum - leftSum - nums[i].
//      b. If leftSum is equal to right sum, return the current index i.
// 4. If no pivot index is found, return -1.

#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }
    
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        int rightSum = totalSum - leftSum - nums[i];
        if (leftSum == rightSum) {
            return i;
        }
        leftSum += nums[i];
    }
    
    return -1; // No pivot index found
}