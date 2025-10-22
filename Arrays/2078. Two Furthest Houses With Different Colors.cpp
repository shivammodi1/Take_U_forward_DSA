#include <bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &c)
{
    int n = c.size();
    int maxDiff = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (c[j] != c[i])
            {
                maxDiff = max(maxDiff, j - i);
            }
        }
    }

    return maxDiff;
}