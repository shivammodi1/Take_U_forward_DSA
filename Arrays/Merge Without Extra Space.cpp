#include <bits/stdc++.h>
using namespace std;
// Input: a[] = [2, 4, 7, 10], b[] = [2, 3]
// Output: a[] = [2, 2, 3, 4], b[] = [7, 10]
// Explanation: After merging the two non-decreasing arrays, we get, [2, 2, 3, 4, 7, 10]

void mergeArrays(vector<int> &a, vector<int> &b)
{
    // code here
    vector<int>ans;
    int n=a.size();
    int m=b.size();
    for(int i=0;i<n;i++){
        ans.push_back(a[i]);
    }

    for(int i=0;i<m;i++){
        ans.push_back(b[i]);
    }

    for(int i=0;i<n;i++){
        a[i] = ans[i];
    }

    for(int i=n;i<ans.size();i++){
        b[i-n] = ans[i];
    }

}

int main()
{
}