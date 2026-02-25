#include<bits/stdc++.h>
using namespace std;


//         1
//      /   \
//     2     3
//    / \
//   4   5
// Output: [[1,2,4],[1,2,5],[1,3]]

void Helper(Node* root,vector<int>&res,vector<vector<int>>&ans){
    if(!root){
        return;
    }
    // Step 1: Add current node to path
    res.push_back(root->data);
    // Step 2: Check if it's a leaf node
    // If it's a leaf node, add the path to ans
    if(!root->left && !root->right){
        ans.push_back(res);
    }
    // Step 3: Recur for left and right subtree
    Helper(root->left,res,ans);
    Helper(root->right,res,ans);
    res.pop_back(); // Backtrack to explore other paths
}

vector<vector<int>> Paths(Node* root){
    vector<int>res;
    vector<vector<int>>ans;
    if(!root){
        return ans;
    }
    Helper(root,res,ans);
    return ans;
}

int main(){
    return 0;
}