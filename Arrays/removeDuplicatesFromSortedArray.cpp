#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if (n <= 1)
        return n;

    int j = 0; // index for unique elements
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1; // new length of array with unique elements
}

int main() {
    int arr[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int newLen = removeDuplicates(arr, n);

    cout << "After removing duplicates: ";
    for (int i = 0; i < newLen; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
