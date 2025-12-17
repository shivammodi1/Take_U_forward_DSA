// The solution set must not contain duplicate subsets. Return the solution in any order.
// Example 1:
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

#include<bits/stdc++.h>
using namespace std;

void Helper(int index,vector<int> &arr,vector<int>& subarr, set<vector<int>>& st){
   if(index == arr.size()){
         st.insert(subarr);
         return;
   }

   // pick the element
   subarr.push_back(arr[index]);
   Helper(index + 1, arr, subarr, st);
   // not pick the element
    subarr.pop_back();
    Helper(index + 1, arr, subarr, st);
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    set<vector<int>> st;
    vector<int> subarr;
    // sort the array to handle duplicates
    sort(nums.begin(), nums.end());
    int index = 0;
    Helper(index, nums, subarr, st);
    
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}



int main(){
    return 0;
}