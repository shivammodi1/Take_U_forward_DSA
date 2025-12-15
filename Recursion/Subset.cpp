#include<bits/stdc++.h>
using namespace std;

void Helper(int index,vector<int> &arr,vector<int>&subset, vector<vector<int>>& result){
    if(index == arr.size()){
        result.push_back(subset);
        return;
    }

    // include the element
    subset.push_back(arr[index]);
    Helper(index + 1, arr, subset, result);
    // exclude the element
    subset.pop_back();
    Helper(index + 1, arr, subset, result);
}

vector<vector<int>> subsets(vector<int>& arr){
    vector<int> subset;
    vector<vector<int>> result;
    Helper(0, arr, subset, result);
    return result;
}

int main(){
    return 0;
}

    //                                []
    //                                |
    //                           (index = 0)
    //                                |
    //                      ┌──────── include 1 ────────┐
    //                      |                           |
    //                     [1]                         []
    //                      |                            |
    //                (index = 1)                  (index = 1)
    //                      |                            |
    //            ┌── include 2 ──┐             ┌── include 2 ──┐
    //            |               |             |               |
    //          [1,2]            [1]           [2]             []
    //            |               |             |               |
    //      (index = 2)      (index = 2)   (index = 2)     (index = 2)
    //            |               |             |               |
    //     ┌ include 3  ┐  ┌ include 3  ┐ ┌ include 3  ┐  ┌ include 3 ┐
    //     |            |  |            | |            |  |           |
    //  [1,2,3]      [1,2] [1,3]      [1] [2,3]      [2] [3]          []

    // final output:- [[],[3],[2],[2,3],[1],[1,3],[1,2],[1,2,3]]