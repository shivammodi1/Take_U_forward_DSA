/* 
    Heap Sort:
    - We restructured the given array and form the max heap or min heap.
    - step 1. Build the max heap from the given array.
    - step 2. Repeatedly swap root with last element
    - step 3. Reduce the heap size by 1 kyuki last element is at its correct position.
    - step 4. Heapify the root of the tree.
    Time Complexity: O(n log n)
    Space Complexity: O(1)
*/

#include<bits/stdc++.h>
using namespace std;

// heapify function
void heapify(vector<int>& arr, int n, int i){
    int largest = i; // Initialize largest as root
    int left = 2*i + 1; // left child index
    int right = 2*i + 2; // right child index

    // If left child is larger than root
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    // If right child is larger than largest so far
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    // If largest is not root
    if(largest != i){
        swap(arr[i], arr[largest]); // swap root with largest

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}


// HeapSort
void heapSort(vector<int>& arr){
    //step 1.
    for(int i = arr.size()/2 - 1; i >= 0; i--){
        heapify(arr, arr.size(), i);
    }

    // step 2.
    for(int i=arr.size()-1;i>=0;i--){
        swap(arr[0],arr[i]);
        heapify(arr, i, 0); // arr , size, index
    }
}

int main(){
    return 0;
}