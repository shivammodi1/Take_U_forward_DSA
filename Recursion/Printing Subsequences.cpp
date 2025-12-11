#include <bits/stdc++.h>
using namespace std;

// [3,1,2]
// Subsequences are different from Subarrays
// []
// [3] [1] [2]
// [3,1] [3,2] [1,2]
// [3,1,2]

// Method:- Recursion (Take or Not Take)

void findSubsequences(int curr, vector<int> &arr,vector<int> &subarr, vector<vector<int>> &res)

{
    //base case
    if (curr == arr.size())
    {
        res.push_back(subarr);
        return;
    }

    // take the element
    subarr.push_back(arr[curr]);
    findSubsequences(curr + 1, arr, subarr, res);
    //not take the element
    subarr.pop_back();
    findSubsequences(curr + 1, arr, subarr, res);
}

// recursion tree
//                                []
//                          /               \
//                     take 3               not take 3
//                      /                       \
//                    [3]                        []
//               /            \             /            \
//          take 1        not take 1   take 1        not take 1
//           /                \           /               \
//        [3,1]              [3]        [1]               []
//        /     \          /    \      /    \           /     \
//  take 2   not 2   take 2  not 2  take 2  not 2   take 2   not 2
//    |         |       |       |      |       |        |         |
// [3,1,2]   [3,1]   [3,2]    [3]    [1,2]    [1]      [2]        []


int main()
{
    vector<int> arr = {3, 1, 2};
    vector<vector<int>> res;
    vector<int> subarr;
    findSubsequences(0, arr, subarr, res);

    for (auto vec : res)
    {
        cout << "[ ";
        for (auto ele : vec)
        {
            cout << ele << " ";
        }
        cout << "] ";
    }
    return 0;
}