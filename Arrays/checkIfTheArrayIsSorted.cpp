#include<bits/stdc++.h>
using namespace std;

// Time Complexity is O(n)
// Just Travese the array if any Previous number > current -> return false

bool isSorted(int arr[],int n){
    if(n==1){
        return 1;
    }

    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    if(isSorted(arr,n)){
        cout<<"Array is Sorted"<<endl;
    }else{
        cout<<"Array is not Sorted"<<endl;
    }
    return 0;
}