#include<bits/stdc++.h>
using namespace std;

// reverse array using recursion
void reverse(vector<int>&arr,int st,int end){
    if(st>=end){
        return;
    }
    swap(arr[st],arr[end]);
    reverse(arr,st+1,end-1);
}
// Recusrion Tree
//                          reverse(arr,0,8)
//                         /               \
//                 swap(arr[0],arr[8])     reverse(arr,1,7)
//                                              |
//                               --------------------------------
//                               |                              |
//                     swap(arr[1],arr[7])          reverse(arr,2,6)
//                                                        |
//                                      ------------------------------------
//                                      |                                  |
//                            swap(arr[2],arr[6])            reverse(arr,3,5)
//                                                                 |
//                                            ---------------------------------------
//                                            |                                     |
//                                  swap(arr[3],arr[5])              reverse(arr,4,4)
//                                                                             |
//                                                                        base case

// Method 2: using one pointer
void reverseArr(vector<int>&arr,int index,int n){
    if(index>=n){
        return;
    }
    swap(arr[index],arr[n-1-index]);
    reverseArr(arr,index+1,n);
}
// Recusrion Tree
//                          reverseArr(arr,0,9)
//                         /               \
//                 swap(arr[0],arr[8])     reverseArr(arr,1,9)
//                                              |
//                               --------------------------------
//                               |                              |
//                           swap(arr[1],arr[7])          reverseArr(arr,2,9)     
//                                                        |
//                                      ------------------------------------
//                                      |                                  |
//                            swap(arr[2],arr[6])            reverseArr(arr,3,9)
//                                                                 |
//                                            ---------------------------------------
//                                            |                                     |
//                                  swap(arr[3],arr[5])              reverseArr(arr,4,9)
//                                                                             |
//                                                                        base case (where index>=n/2)


int main(){
    vector<int>arr={1,2,3,4,5,6,7,8,9};
    int n=arr.size();
    reverse(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}