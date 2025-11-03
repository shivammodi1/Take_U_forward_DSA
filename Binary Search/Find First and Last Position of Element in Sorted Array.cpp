#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstIndex(vector<int> &arr, int x)
    {
        int n = arr.size();
        int st = 0;
        int end = n - 1;
        int ans = -1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                end = mid - 1;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }

    int lastIndex(vector<int> &arr, int x)
    {
        int n = arr.size();
        int st = 0;
        int end = n - 1;
        int ans = -1;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (arr[mid] == x)
            {
                ans = mid;
                st = mid + 1;
            }
            else if (arr[mid] > x)
            {
                end = mid - 1;
            }
            else
            {
                st = mid + 1;
            }
        }
        return ans;
    }

    vector<int> find(vector<int> &arr, int x)
    {
        // code here
        int n = arr.size();
        vector<int> ans(2, -1);

        int start = firstIndex(arr, x);
        int last = lastIndex(arr, x);

        ans[0] = start;
        ans[1] = last;
        return ans;
    }
};