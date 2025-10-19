#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int>& arr, int key) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i; // return index where element is found
        }
    }
    return -1; // not found
}

int main() {
    int n, key;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> key;

    int index = linearSearch(arr, key);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
