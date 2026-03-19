#include<bits/stdc++.h>
using namespace std;

/*
    ================== QUESTION ==================

    - Given an array of integers (can be negative and positive),
      design a data structure that:
        1. Stores all elements
        2. Supports searching in O(1) time

    - Constraint:
        Range of elements = [-1000, 1000]


    ================== TECHNIQUE ==================

    - We use Hashing (Direct Addressing Technique)

    - Since range is fixed and small, we can directly map each number
      to an index.

    - To handle negative numbers:
        -> Use 2D array:
            Row 0 → Negative numbers
            Row 1 → Positive numbers

    - Index mapping:
        value = x
        index = abs(x)


    ================== APPROACH ==================

    1. Create a 2D boolean array:
            hash[2][1001]

    2. Traverse the array:
        - If element >= 0:
                mark hash[1][element] = true
        - Else:
                mark hash[0][abs(element)] = true

    3. For searching:
        - If value >= 0:
                check hash[1][value]
        - Else:
                check hash[0][abs(value)]

    4. If value exists → return true
       else → return false


    ================== TIME & SPACE ==================

    - Time Complexity:
        Insertion  -> O(n)
        Searching  -> O(1)

    - Space Complexity:
        O(1) (since size is fixed)


    ================== CODE ==================
*/

#define MAX 1000

bool hash[2][MAX + 1];

bool insert(int arr[],int n){
    for(int i=0;i<n;i++){
        if(arr[i]>=0){
            hash[1][arr[i]] = true;
        }else{
            hash[0][abs(arr[i])] = true;
        }
    }
    return true;
}

bool searching(int val){
    if(val>=0){
        return hash[1][val];
    }
    return hash[0][abs(val)];
}

int main(){
    int n;
    cin >> n;

    int arr[n];

    // memset(array_name, value, size_in_bytes);
    memset(hash, false, sizeof(hash));// Initialize hash table

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    insert(arr, n);

    int q;
    cin >> q;

    while(q--){
        int x;
        cin >> x;

        if(searching(x)){
            cout << "Found\n";
        }else{
            cout << "Not Found\n";
        }
    }
}