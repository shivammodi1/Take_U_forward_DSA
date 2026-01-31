// # 1877. Minimize Maximum Pair Sum in Array

int minPairSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    int i = 0;
    int j = n - 1;
    int maxPairSum = INT_MIN;
    while (i < j)
    {
        int sum = nums[i] + nums[j];
        maxPairSum = max(maxPairSum, sum);
        i++;
        j--;
    }
    return maxPairSum;
}

// ## Problem Summary
// Given an array `nums` of even length, we need to divide the elements into `n/2` pairs such that:
// - Every element is used exactly once
// - The **maximum pair sum** among all pairs is **as small as possible**

// The **pair sum** of a pair `(a, b)` is `a + b`.

// ---

// ## Key Observation
// The maximum pair sum becomes large when **two large numbers** are paired together.

// To minimize this maximum value, we should:
// - Pair **large numbers with small numbers**
// - Avoid pairing **large + large** or **small + small**

// ---

// ## Optimal Strategy (Greedy Idea)

// 1. **Sort the array**
//    - This helps clearly identify the smallest and largest elements.

// 2. **Form pairs as follows:**
//    - Pair the **smallest element** with the **largest element**
//    - Pair the **second smallest** with the **second largest**
//    - Continue this process until all elements are paired

// 3. **Track the maximum pair sum**
//    - For every pair, calculate the sum
//    - The answer is the **maximum** of these pair sums

// ---

// ## Why This Works
// - Pairing the smallest with the largest balances the sums
// - This prevents any single pair from becoming too large
// - As a result, the **worst (maximum) pair sum** is minimized

// This greedy approach ensures the most balanced pairing possible.

// ---

// ## Example 1

// **Input:**
// `[3, 5, 2, 3]`

// **Sorted Array:**
// `[2, 3, 3, 5]`

// **Pairs Formed:**
// - `(2, 5)` → sum = 7
// - `(3, 3)` → sum = 6

// **Maximum Pair Sum:**
// `7`

// ---

// ## Example 2

// **Input:**
// `[3, 5, 4, 2, 4, 6]`

// **Sorted Array:**
// `[2, 3, 4, 4, 5, 6]`

// **Pairs Formed:**
// - `(2, 6)` → sum = 8
// - `(3, 5)` → sum = 8
// - `(4, 4)` → sum = 8

// **Maximum Pair Sum:**
// `8`
