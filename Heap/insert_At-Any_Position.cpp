#include <bits/stdc++.h>
using namespace std;

void decreaseKey(vector<int> &arr, int i, int new_val)
{

    arr[i] = new_val;

    while (i != 0 && arr[(i - 1) / 2] > arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int main()
{

    vector<int> arr = {10, 20, 15, 30, 40};

    int index = 3;     // element 30
    int new_value = 5; // decrease key

    decreaseKey(arr, index, new_value);

    for (int x : arr)
    {
        cout << x << " ";
    }
}

// Decrease Key in Min Heap

// Decrease Key ka matlab hota hai kisi node ki value ko chhota (decrease) karna aur phir heap property ko maintain karna.