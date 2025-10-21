#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the next permutation
// method 1 Using Library
// next_permutation
void nextPermutation(vector<int> &arr)
{

    // Rearranges elements into the next lexicographical order
    // If already last permutation, rearranges to the smallest
    next_permutation(arr.begin(), arr.end());
}

// method 2
// Generate All posible permute
// than sort
// search Linearlly
// return next

void generatePermute(vector<vector<int>> &res, vector<int> &arr, int index)
{
    // Base case: if index equals array size, push current permutation
    if (index == arr.size())
    {
        res.push_back(arr);
        return;
    }

    // Start from index to avoid duplicate permutations and unnecessary swaps
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[i], arr[index]);             // Fix element at index
        generatePermute(res, arr, index + 1); // Recurse for next index
        swap(arr[i], arr[index]);             // Backtrack to original state
    }
}

void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> res;
    generatePermute(res, nums, 0);

    // Sort all permutations lexicographically
    sort(res.begin(), res.end());

    // Find current permutation and set nums to next lexicographic one or wrap around
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i] == nums)
        {
            if (i < res.size() - 1)
            {
                nums = res[i + 1];
            }
            else
            {
                nums = res[0];
            }
            break;
        }
    }
}

int main()
{

    vector<int> arr = {2, 4, 1, 7, 5, 0};

    nextPermutation(arr);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}