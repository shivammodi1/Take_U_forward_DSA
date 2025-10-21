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

    // index == n than push arr into res than return
    if (index == arr.size())
    {
        res.push_back(arr);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        // swap the numbers
        swap(arr[i], arr[index]);

        generatePermute(res, arr, index + 1);

        // backtrack to original one
        swap(arr[i], arr[index]);
    }
}

void nextPermutation(vector<int> &nums)
{
    vector<vector<int>> res;
    //generate all the possible permutation
    generatePermute(res,nums,0);

    // Sort all permutations lexicographically
    sort(res.begin(), res.end());

    for(int i=0;i<nums.size();i++){
        if(res[i]==nums){
            // If it's not the last permutation
            if(i<res.size()-1){
                nums=res[i+1];
            }
            // If it is last permutation than store 0th index value
            else{
                nums=res[0];
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