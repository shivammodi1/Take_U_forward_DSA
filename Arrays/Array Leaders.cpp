#include <bits/stdc++.h>
using namespace std;

//method 1 
//using Normal Method all possible cases
// T.C. -> O(n^2);
vector<int> Leaders(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int maxEle = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxEle = false;
                break;
            }
        }

        if (maxEle)
        {
            ans.push_back(arr[i]);
        }
    }
}


//Method 2
// Optimal Solution
//T.C. -> O(n)
vector<int> leaders(vector<int> &arr)
{
    // Code here
    vector<int> ans;
    int n = arr.size();

    int maxEle = INT_MIN;
    // We start traversing the array from the last element.
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            maxEle = arr[i];
        }
        // Comparing the current element with the maximum element stored.
        // If current element is greater than or equal to the max, we add the element.
        if (arr[i] >= maxEle)
        {
            maxEle = max(maxEle, arr[i]);
            ans.push_back(maxEle);
        }
    }
    reverse(ans.begin(), ans.end()); // Finally reversing the vector in which leaders are stored.

    return ans;
}

int mmain()
{
}