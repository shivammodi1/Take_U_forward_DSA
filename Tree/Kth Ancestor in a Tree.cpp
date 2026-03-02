#include<bits/stdc++.h>
using namespace std;

// Kth Ancestor in a Tree
// PROBLEM:
// Given a tree and a node, find the kth ancestor of the node in the tree. If there is no such ancestor, return -1.
// Example:
// Input:    1
//         /   \
//        2     3
//       / \
//      4   5
// Node = 5, K = 2
// Output: 1 -> for node=4, 2nd ancestor is 1 

//Approach:
// 1. Basically hum kya karege phale hum root se node ka path find kr lenege, alag se function bana ke.
// 2. than kth ancestor ia automatically at path[path.size() - 1 - k] hoga,
// 3. if k>= path.size() → return -1

bool rootToNodePath(Node* root, int node, vector<int>& path) {
    if (!root) return false;

    path.push_back(root->data);

    if (root->data == node) return true;

    if (rootToNodePath(root->left, node, path) || rootToNodePath(root->right, node, path)) {
        return true;
    }

    path.pop_back(); // backtrack
    return false;
}

int KthAncestor(Node* root,int node,int k){
    vector<int> path;
    // find path from root to node
    if(!rootToNodePath(root, node, path)) {
        return -1; // node not found in tree
    }
    int n = path.size();
    if(k >= n) return -1; // if k is greater than or equal to path size, no ancestor exists
    return path[n - 1 - k]; // kth ancestor is at index n-1-k

}

int main(){
    return 0;
}