// Given an integer array nums, return the number of reverse pairs in the array.

// A reverse pair is a pair (i, j) where:

// 0 <= i < j < nums.length and
// nums[i] > 2 * nums[j].

// Example 1:

// Input: nums = [1,3,2,3,1]
// Output: 2
// Explanation: The reverse pairs are:
// (1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
// (3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

#include <bits/stdc++.h>
using namespace std;

// method 1
//  T.C -> O(n^2)
// Time Limited Exceeded
class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        int n = nums.size();
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long val = (long long)nums[j] * 2;
                if ((long long)nums[i] > val)
                {
                    c++;
                }
            }
        }
        return c;
    }
};

// method 2
// using Merge sort
class Solution {
public:

    void merge(vector<int> &arr, int low, int mid, int high)
    {
        vector<int> temp;    // temporary array
        int left = low;      // starting index of left half of arr
        int right = mid + 1; // starting index of right half of arr

        // storing elements in the temporary array in a sorted manner//

        while (left <= mid && right <= high)
        {
            if (arr[left] <= arr[right])
            {
                temp.push_back(arr[left]);
                left++;
            }
            else
            {
                temp.push_back(arr[right]);
                right++;
            }
        }

        // if elements on the left half are still left //

        while (left <= mid)
        {
            temp.push_back(arr[left]);
            left++;
        }

        //  if elements on the right half are still left //
        while (right <= high)
        {
            temp.push_back(arr[right]);
            right++;
        }

        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int right = mid + 1;
        int cnt = 0;
        for (int i = low; i <= mid; i++)
        {
           while (right <= high && (long long)arr[i] > 2LL * arr[right]){
            right++;
           }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }

    int mergeSort(vector<int> &arr, int low, int high)
    {
        int cnt = 0;
        if (low >= high)
            return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(arr, low, mid);        // left half
        cnt += mergeSort(arr, mid + 1, high);   // right half
        cnt += countPairs(arr, low, mid, high); // Modification
        merge(arr, low, mid, high);             // merging sorted halves
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
};