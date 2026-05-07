// Merge Sort
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>&arr,int st,int mid, int end){
    int n1 = mid - st + 1;
    int n2 = end - mid;

    vector<int>left(n1), right(n2);

    for(int i=0;i<n1;i++){
        left[i] = arr[st + i];
    }
    for(int i=0;i<n2;i++){
        right[i] = arr[mid + 1 + i];
    }

    int i=0, j=0, k=st;
    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i < n1){
        arr[k++] = left[i++];
    }
    while(j < n2){
        arr[k++] = right[j++];
    }
}


void mergeSort(vector<int>& arr, int left, int right){
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for (int num : arr) {
        cout << num << " ";
    }
    return 0;
}