#include<bit/stdc++.h>
using namespace std;
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
//                            [1,2,3]
//                /               |               \
//             [2,3]            [1,3]            [1,2]
//          /    \              /   \             /    \
//        [3]    [2]        [3]     [1]       [2]     [1]
//       /        \        /         \      /         \
//     []          []    []           []   []           []
// at the leaf nodes we have our permutations
// Time Complexity: O(N*N!) where N is the number of elements in the input array.
// Space Complexity: O(N) for the recursion stack and O(N!) for storing all the

// method 1:
void Helper(vector<int>& nums,int index,vector<vector<int>>& res){
    // base case
    if(index==nums.size()){
        res.push_back(nums);
        return;
    }
    for(int i=index;i<nums.size();i++){
        swap(nums[index],nums[i]); // swap the current index with the loop index
        Helper(nums,index+1,res); // recursive call
        swap(nums[index],nums[i]); // backtracking
    }
}

vector<vector<int>> permute(vector<int>& nums){
    int index = 0;
    vector<vector<int>> result;
    Helper(nums, index, result);
    return result;
}

int main(){
    return 0;
}
