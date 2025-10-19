// Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
// Note: You need to solve this problem without utilizing the built-in sort function.

// Examples:

// Input: arr[] = [0, 1, 2, 0, 1, 2]
// Output: [0, 0, 1, 1, 2, 2]
// Explanation: 0s, 1s and 2s are segregated into ascending order.
// Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
// Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
// // Explanation: 0s, 1s and 2s are segregated into ascending order.

#include <bits/stdc++.h>
using namespace std;

void sort012(vector<int> &arr)
{
    int count0=0;
    int count1=0;
    int count2=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            count0++;
        }else if(arr[i]==1){
            count1++;
        }else{
            count2++;
        }
    }

    int i=0;
    while(count0--){
        arr[i]=0;
        i++;
    }
    while(count1--){
        arr[i]=1;
        i++;
    }
    while(count2--){
        arr[i]=2;
        i++;
    }


}

int main()
{
}