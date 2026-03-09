#include<bits/stdc++.h>
using namespace std;


// Normal BST to Balanced BST
// Appraoch:
// step 1. Store all the node in vector in sorted order using inorder traversal
// step 2. Use the sorted vector to construct a balanced BST using divide and conquer approach
//         - a. set pointer st = 0 and end = size of vector - 1
//         - b. find the mid of the vector and create a new node with the mid value
//         - c. After create new Node recursively call the function for left and right sub tree
//               - i.  newNode->left = constructBST(st, mid - 1, vector)
//               - ii. newNode->right = constructBST(mid + 1, end, vector)
//         - d. return the new node

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        val = value;
        left = nullptr;
        right = nullptr;
    }
};

void inorderTraversal(TreeNode* root, vector<int>& arr) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left, arr);
    arr.push_back(root->val);
    inorderTraversal(root->right, arr);
}

TreeNode* constructBST(int st, int end, vector<int>& arr) {
    if (st > end) {
        return nullptr;
    }
    int mid = st + (end - st) / 2;
    TreeNode* newNode = new TreeNode(arr[mid]); // create new node with mid value
    newNode->left = constructBST(st, mid - 1, arr); // for left st->mid-1
    newNode->right = constructBST(mid + 1, end, arr);// for right mid+1->end
    return newNode;
}

TreeNode* balancedBST(TreeNode* root){
    vector<int> arr;
    inorderTraversal(root, arr);
    // st = 0, end = size of vector - 1 , vector = arr
    TreeNode* ans = constructBST(0, arr.size() - 1, arr);
    return ans;
}