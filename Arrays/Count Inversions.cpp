// Given an array of integers arr[]. You have to find the Inversion Count of the array. 
// Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

// Examples:

// Input: arr[] = [2, 4, 1, 3, 5]
// Output: 3
// Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).
#include<bits/stdc++.h>
using namespace std;

// Method 1
// T.C -> O(N^2)
class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int N = arr.size();
        int count = 0;
    for(int i = 0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(arr[i]>arr[j] && i<j) {
                count++;
            }
        }
    }
    return count;
    }
};


//method 2
// T.C -> O(n log n)

class Solution {
  public:
    long long count = 0; //variable to store total inversions

    // Function to merge two sorted halves and count inversions
    void MergeArray(vector<int>& arr, int l, int mid, int r) {

        // Creating temporary arrays for left and right halves
        int n1 = mid - l + 1;
        int n2 = r - mid;

        vector<int> left(n1);
        vector<int> right(n2);

        // Copy elements into left[] array
        for(int i = 0; i < n1; i++)
            left[i] = arr[l + i];

        // Copy elements into right[] array
        for(int i = 0; i < n2; i++)
            right[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = l;

        // Merge both sorted arrays
        while(i < n1 && j < n2) {

            // If left element is smaller or equal, no inversion
            if(left[i] <= right[j]) {
                arr[k++] = left[i++];
            }
            // If right[j] < left[i], then all remaining elements in left[]
            // from index i to end are greater than right[j]
            else {
                count += (n1 - i);  // count all remaining greater elements
                arr[k++] = right[j++];
            }
        }

        // Copy remaining elements of left[], if any
        while(i < n1) arr[k++] = left[i++];

        // Copy remaining elements of right[], if any
        while(j < n2) arr[k++] = right[j++];
    }

    // Standard merge sort function
    void MergeSort(vector<int>& arr, int l, int r) {
        if(l >= r) return; //base condition: single element is always sorted

        int mid = l + (r - l) / 2;

        // Sort left half
        MergeSort(arr, l, mid);

        // Sort right half
        MergeSort(arr, mid + 1, r);

        // Merge sorted halves and count inversions
        MergeArray(arr, l, mid, r);
    }

    // Function to return total inversion count
    long long inversionCount(vector<int>& arr) {
        MergeSort(arr, 0, arr.size() - 1);
        return count;
    }
};
