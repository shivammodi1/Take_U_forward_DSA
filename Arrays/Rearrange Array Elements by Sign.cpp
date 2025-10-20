#include <bits/stdc++.h>
using namespace std;
// Input : arr[] = [ 9, 4, -2, -1, 5, 0, -5, -3, 2 ] 
// Output : [ 9, -2, 4, -1, 5, -5, 0, -3, 2 ]
//  Explanation : The positive numbers are[9, 4, 5, 0, 2] and the negative integers are[-2, -1, -5, -3].Since, 
//  we need to start with the positive integer first and then negative integer and so on(by maintaining the relative order as well), 
//  hence we will take 9 from the positive set of elements and then - 2 after that 4 and then - 1 and so on.

void rearrange(vector<int> &arr)
{
    // code here
    vector<int> a1, a2;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            a1.push_back(arr[i]);
        }
        else
        {
            a2.push_back(arr[i]);
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < a1.size())
        {
            arr[j++] = a1[i];
        }
        if (i < a2.size())
        {
            arr[j++] = a2[i];
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    rearrange(arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
