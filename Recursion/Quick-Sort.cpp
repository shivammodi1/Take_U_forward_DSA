#include<bits/stdc++.h>
using namespace std;

// Approach
// 1. Choose a pivot element from the array.
//  ==> Pivot element can be chosen from start, end or middle of the array.
// 2. Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
// 3. Recursively apply the above steps to the sub-arrays.

// Time Complexity: O(n log n) on average, O(n^2) in the worst case.
// Space Complexity: O(log n) due to recursive stack space.


int findPartitionIndex(vector<int> &arr,int st,int end){
    int pivot = arr[st];
    int i = st; // left pointer
    int j = end; // right pointer

    while(i<j){
        // Move i to the right until an element greater than the pivot is found
        while(arr[i]<=pivot && i<end){
            i++;
        }
        // Move j to the left until an element less than or equal to the pivot is found
        while(arr[j]>pivot && j>st){
            j--;
        }
        // Swap elements at i and j if i is less than j
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    // Place the pivot element at its correct position
    swap(arr[st],arr[j]);
    return j; // Return the partition index
}

void QuickSort(vector<int> &arr,int st,int end){

    if(st<end){
        int partitionIndex = findPartitionIndex(arr,st,end);
        QuickSort(arr,st,partitionIndex-1);
        QuickSort(arr,partitionIndex+1,end);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    QuickSort(arr,0,n-1);
    cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}



// TREE DIAGRAM
// Consider the array: [10, 7, 8, 9, 10, 5]
// 1. Choose pivot as first element: 10
//                    Left Sub-array    Pivot       Right Sub-array
//                      [7, 8, 9, 5]     [10]         [10]
// 2. Recursively apply QuickSort on Left Sub-array [7, 8, 9, 5]
//    Choose pivot as first element: 7
//                    Left Sub-array    Pivot       Right Sub-array
//                      [5]             [7]         [8, 9]
// 3. Recursively apply QuickSort on Right Sub-array [8, 9]
//    Choose pivot as first element: 8
//                    Left Sub-array    Pivot       Right Sub-array
//                      []              [8]         [9]
// 4. Base case reached for all sub-arrays, start merging back:
//   Merging [5], [7], [8], [9], [10], [10] results in sorted array: [5, 7, 8, 9, 10, 10]

//                    [10, 7, 8, 9, 10, 5,11]
//              |______________________________|
//                      /                \
//             [7, 8, 9, 5]                [10,11]
//        |________________|              |________|
//              /          \                /      \
//            [5]            [8, 9]      [10]      [11]
//                        |__________|
//                        /        \
//                         []        [9]   

