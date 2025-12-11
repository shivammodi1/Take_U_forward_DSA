// Print all the subsequences of an array whose sum is equal to a given target sum.
#include<bits/stdc++.h>
using namespace std;

void findSubsequences(int index,vector<int>& arr,vector<int>& subarr,
                      vector<vector<int>>& res, int target, int currSum)
{
    // valid subsequence reached
    if(index == arr.size()){
        if(currSum == target){
            res.push_back(subarr);
        }
        return;
    }


    // take the element
    subarr.push_back(arr[index]);
    findSubsequences(index + 1, arr, subarr, res, target, currSum + arr[index]);

    // not take the element
    subarr.pop_back();
    findSubsequences(index + 1, arr, subarr, res, target, currSum);
}
// recursion tree 
//             [1,2,1],sum = 0
//                 [], sum=0
//           /                      \
//      [1], sum=1                [], sum=0
//      /         \               /          \
// [1,2],3      [1],1           [2],2          [],0
//  /     \      /   \         /     \        /      \
// [1,2,1],4 [1,2],3 [1,1],2 [1],1 [2,1],3 [2],2 [1],1 [],0

// for target = 2 
// [1, 2]
// [2, 1]


int main(){
    vector<int> arr = {1, 2, 1};
    int target = 3;

    vector<vector<int>> res;
    vector<int> subarr;

    findSubsequences(0, arr, subarr, res, target, 0);

    for(auto &vec : res){
        cout << "[ ";
        for(auto &x : vec){
            cout << x << " ";
        }
        cout << "] ";
    }

    return 0;
}
