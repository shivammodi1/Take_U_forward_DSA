// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123" "132" "213" "231" "312" "321"
// Given n and k, return the kth permutation sequence.
// Example 1:
// Input: n = 3, k = 3
// Output: "213"

#include <bits/stdc++.h>
using namespace std;

// Method 1: Generate all permutations and return k-1 th indexed permutation
// Time Complexity: O(n*n!)
// Space Complexity: O(n!)
// It will give TLE for large n
void Permute(string &num, int index, vector<string> &result)
{
    if (index == num.size())
    {
        result.push_back(num);
        return;
    }

    for (int i = index; i < num.size(); i++)
    {
        swap(num[index], num[i]);
        Permute(num, index + 1, result);
        swap(num[index], num[i]);
    }
}

string getPermutation(int n, int k)
{
    string num;
    for (int i = 1; i <= n; i++)
    {
        num += to_string(i);
    }

    vector<string> result;
    int index = 0;
    Permute(num, index, result);
    // sort the result to get lexicographical order
    sort(result.begin(), result.end());
    return result[k - 1]; // k-1 for 0 based indexing
}

// Method 2: Optimal Approach using Factorial Number System
// Time Complexity: O(n^2)
// Space Complexity: O(n)

// Example:
// n = 4, k = 17
// Since permutation indexing is 1-based, convert it to 0-based
// k = k - 1 = 16

// Initial numbers:
// [1, 2, 3, 4]

// Step 1: Fix the first digit
// Remaining digits = 3
// Number of permutations for each fixed digit = 3! = 6
//
// 1 + [2,3,4] -> 6 permutations
// 2 + [1,3,4] -> 6 permutations
// 3 + [1,2,4] -> 6 permutations
// 4 + [1,2,3] -> 6 permutations
//
// Index = 16 / 6 = 2
// Selected digit = 3
// New k = 16 % 6 = 4
// Remaining digits = [1, 2, 4]

// Step 2: Fix the second digit
// Remaining digits = 2
// Number of permutations for each fixed digit = 2! = 2
//
// 1 + [2,4] -> 2 permutations
// 2 + [1,4] -> 2 permutations
// 4 + [1,2] -> 2 permutations
//
// Index = 4 / 2 = 2
// Selected digit = 4
// New k = 4 % 2 = 0
// Remaining digits = [1, 2]

// Step 3: Fix the third digit
// Remaining digits = 1
// Number of permutations for each fixed digit = 1! = 1
//
// 1 + [2] -> 1 permutation
// 2 + [1] -> 1 permutation
//
// Index = 0 / 1 = 0
// Selected digit = 1
// New k = 0 % 1 = 0
// Remaining digits = [2]

// Step 4: Fix the last digit
// Only one digit left
// Selected digit = 2

// Final permutation sequence = "3412"

string getPermutationOptimal(int n, int k)
{
    vector<int> nums;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        nums.push_back(i);
        fact *= i;
    }
    nums.push_back(n);
    k = k - 1; // convert to 0-based indexing
    string result = "";
    while(true){
        int index = k / fact; // index of current digit
        result = result + to_string(nums[index]);
        nums.erase(nums.begin() + index); // remove used digit
        if(nums.size() == 0){
            break; // all digits used
        }
        k = k % fact; // new k
        fact = fact / nums.size(); // new factorial
    }
    return result;
    
}

int main()
{
    return 0;
}