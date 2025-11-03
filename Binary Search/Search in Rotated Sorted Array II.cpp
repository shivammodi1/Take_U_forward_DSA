// Given a sorted and rotated array arr[] and a target key. Check whether the key is present in the array or not.

// Note: The array may contains duplicate elements.

// Examples:

// Input: arr[] = [3, 3, 3, 1, 2, 3], key = 3
// Output: true
// Explanation: 3 is present in the array.
// Input: arr[] = [4, 5, 8, 1, 1, 1, 2], key = 6
// Output: false
// Explanation: 6 is not present in the array.

#include <bits/stdc++.h>
using namespace std;

bool search(vector<int> &arr, int key)
{
    // Code here
    int n = arr.size();
    int st=0;
    int end=n-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==key){
            return true;
        }
        // left half is sorted
        if(arr[st]<arr[mid]){
            if(arr[st]<=key && key<arr[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        // right half is sorted
        else if(arr[mid]<arr[end]){
            if(arr[mid]<key && key<=arr[end]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        // duplicates, we can't decide which half is sorted
        else{
            if(arr[st]==arr[mid]){
                st++;
            }
            if(arr[end]==arr[mid]){
                end--;
            }
        }
        
    }
    return false;
}