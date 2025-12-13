#include<bits/stdc++.h>
using namespace std;

void Helper(int index,vector<int>& arr, vector<int>&subarr ,vector<vector<int>>&res , int target,int currSum){
   if(currSum>target){
       return;
   }
    if(currSum==target){
         res.push_back(subarr);
         return;
    }
    if(index==arr.size()){
        return;
    }
    //pick
    subarr.push_back(arr[index]);
    Helper(index,arr,subarr,res,target,currSum+arr[index]); // index is not increased because we can pick same element again
    subarr.pop_back();
    //not pick
    Helper(index+1,arr,subarr,res,target,currSum);
}

vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> res;
        vector<int> subarr;
       
        Helper(0,arr,subarr,res,target,0);
        return res;

}



// Helper(0, [], 0)
// │
// ├── Pick 2     
// │   Helper(0, [2], 2)    index  subarr  currSum
// │   │
// │   ├── Pick 2
// │   │   Helper(0, [2,2], 4)
// │   │   │
// │   │   ├── Pick 2
// │   │   │   Helper(0, [2,2,2], 6)
// │   │   │   │
// │   │   │   ├── Pick 2
// │   │   │   │   Helper(0, [2,2,2,2], 8) ❌ (currSum > target → return)
// │   │   │   │
// │   │   │   └── Not Pick
// │   │   │       Helper(1, [2,2,2], 6)
// │   │   │
// │   │   └── Not Pick
// │   │       Helper(1, [2,2], 4)
// │   │
// │   └── Not Pick
// │       Helper(1, [2], 2)
// │
// └── Not Pick
//     Helper(1, [], 0)
//   │
//   ├── Pick 3
//   │   Helper(1, [3], 3)
//   │   │
//   │   ├── Pick 3
//   │   │   Helper(1, [3,3], 6)
//   │   │   │
//   │   │   ├── Pick 3
//   │   │   │   Helper(1, [3,3,3], 9) ❌ (currSum > target → return)
//   │   │   │
//   │   │   └── Not Pick
//   │   │       Helper(2, [3,3], 6)
//   │   │
//   │   └── Not Pick 
//   │       Helper(2, [3], 3)
//   │
//   └── Not Pick
//       Helper(2, [], 0)
//       │
//      ├── Pick 6
//      │   Helper(2, [6], 6)
//      │   │
//      │   ├── Pick 6
//      │   │   Helper(2, [6,6], 12)
//      │   │   ❌ (currSum > target → return)
//      │   │
//      │   └── Not Pick
//      │       Helper(3, [6], 6)
//      │
//      └── Not Pick
//          Helper(3, [], 0)
//        ❌ (index == arr.size() → return)
// End of recursion tree

int main(){
    return 0;
}





















