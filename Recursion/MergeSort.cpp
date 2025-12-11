#include <bits/stdc++.h>
using namespace std;

void Merge(vector<int> &arr, int st, int mid, int end)
{
    int n1 = mid - st + 1;
    int n2 = end - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[i + st];
    }

    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = st;

    // ---------------- MERGING DRY RUN (Example for [3,1,4]) ----------------
    // left = [3,1]  → after sorting becomes [1,3]
    // right = [4]
    // Compare left[0]=1 and right[0]=4 → 1 goes first
    // Compare left[1]=3 and right[0]=4 → 3 goes next
    // right has 4 left, place it → final = [1,3,4]
    // ----------------------------------------------------------------------

    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void MergeSort(vector<int> &arr, int st, int end)
{
    if (st >= end)
    {
        return;
    }

    int mid = st + (end - st) / 2;

    // ----------------- RECURSION TREE (for input: 3 1 4) ------------------
    // MergeSort(arr,0,2)
    //     mid = 1
    //     /           \
    // MergeSort(0,1)   MergeSort(2,2)
    //
    // MergeSort(arr,0,1)
    //     mid = 0
    //     /       \
    // (0,0)      (1,1)
    //
    // Actual breakdown:
    //
    //                  [3,1,4] (0,2)
    //                 /        \
    //           [3,1] (0,1)      [4] (2,2)
    //            /    \
    //        [3]      [1]      -> merge → [1,3]
    //
    // Final merge: [1,3] + [4] → [1,3,4]
    // ----------------------------------------------------------------------

    MergeSort(arr, st, mid);
    MergeSort(arr, mid + 1, end);
    Merge(arr, st, mid, end);
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);

    for (int i = 0; i < n; i++)
    {
        cin >> ar[i];
    }

    MergeSort(ar, 0, n - 1);

    // Print sorted array
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
}
