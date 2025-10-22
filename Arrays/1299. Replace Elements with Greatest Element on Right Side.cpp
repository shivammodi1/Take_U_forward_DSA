#include <bits/stdc++.h>
using namespace std;

//method 1 
//using Normal Method all possible cases
// T.C. -> O(n^2);

vector<int> replaceElements(vector<int> &arr)
{
    vector<int> ans;
    int n = arr.size();
    if (n == 1)
    {
        return {-1};
    }
    for (int i = 0; i < n; i++)
    {
        int maxEle = -1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > maxEle)
            {
                maxEle = arr[j];
            }
        }
        ans.push_back(maxEle);
    }
    return ans;
}
