#include <bits/stdc++.h>
using namespace std;

// for 0-based index
vector<int> getRow(int rowIndex)
{

    long long ans = 1;
    vector<int> res;
    res.push_back(ans);
    for (int i = 1; i <= rowIndex; i++)
    {
        ans = ans * (rowIndex - i + 1);
        ans /= i;
        res.push_back(ans);
    }
    return res;
}
int main()
{
}