#include <bits/stdc++.h>
using namespace std;

void Helper(int index,vector<int>& arr,vector<int>&subarr,vector<vector<int>>&res,int target,int currSum){
    if(currSum==target){
        res.push_back(subarr);
        return;
    }
    if(currSum>target || index==arr.size()){
        return;
    }

    
    // pick
    subarr.push_back(arr[index]);
    Helper(index+1,arr,subarr,res,target,currSum+arr[index]); // index is increased to avoid picking same element again
    subarr.pop_back();
    // not pick
    int nextIndex=index+1;
    // skip duplicates for not pick case 
    while(nextIndex<arr.size() && arr[nextIndex]==arr[index]){
        nextIndex++;
    }
    Helper(nextIndex,arr,subarr,res,target,currSum);
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    int n = candidates.size();
    vector<vector<int>> res;
    vector<int> subarr;
    // Sort the candidates to handle duplicates
    sort(candidates.begin(), candidates.end());
    Helper(0, candidates, subarr, res, target, 0);
    return res;
}

int main()
{
    return 0;
}