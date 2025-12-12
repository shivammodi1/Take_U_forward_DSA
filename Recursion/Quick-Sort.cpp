#include<bits/stdc++.h>
using namespace std;

// Approach
// 1. Choose a pivot element from the array.
//  ==> Pivot element can be chosen from start, end or middle of the array.
// 2. Partition the array into two sub-arrays: elements less than the pivot and elements greater than the pivot.
// 3. Recursively apply the above steps to the sub-arrays.


void QuickSort(vector<int> &arr,int st,int end){

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