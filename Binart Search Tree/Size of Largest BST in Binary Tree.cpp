#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Find the size of the Largest BST present in a Binary Tree.

    Example Tree:

            5
           / \
          2   4
         / \
        1   3

    Output: 3

    Explanation:
    The subtree rooted at node 2 (nodes 1,2,3) forms the largest BST.
*/


// ---------------------- Node Definition ----------------------
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor to create a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


// ---------------------- Info Structure ----------------------
/*
    This class stores important information about each subtree.

    maxi  -> Maximum value present in the subtree
    mini  -> Minimum value present in the subtree
    isBST -> Tells whether the subtree is a BST or not
    size  -> Number of nodes in the subtree
*/
class Info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};


// ---------------------- Helper Function ----------------------
/*
    solve() function processes each node and returns Info about the subtree.

    It also updates maxSize which stores the size of the largest BST found.
*/
Info solve(Node* root, int &maxSize) {

    // Base Case
    // If the node is NULL, it is considered a valid BST
    if (root == NULL) {
        return {INT_MIN, INT_MAX, true, 0};
    }

    // Recursively get information from left subtree
    Info leftInfo = solve(root->left, maxSize);

    // Recursively get information from right subtree
    Info rightInfo = solve(root->right, maxSize);

    // Create Info object for current node
    Info currNode;

    // Size of subtree rooted at current node
    currNode.size = leftInfo.size + rightInfo.size + 1;

    // Maximum value in current subtree
    currNode.maxi = max(root->data, rightInfo.maxi);

    // Minimum value in current subtree
    currNode.mini = min(root->data, leftInfo.mini);

    /*
        Condition to check if current subtree is BST:

        1. Left subtree must be BST
        2. Right subtree must be BST
        3. Current node value must be greater than max value of left subtree
        4. Current node value must be smaller than min value of right subtree
    */
    if (leftInfo.isBST &&
        rightInfo.isBST &&
        root->data > leftInfo.maxi &&
        root->data < rightInfo.mini) {

        currNode.isBST = true;
    }
    else {
        currNode.isBST = false;
    }

    // If current subtree is BST, update maxSize
    if (currNode.isBST) {
        maxSize = max(maxSize, currNode.size);
    }

    // Return information of current subtree
    return currNode;
}


// ---------------------- Main Function ----------------------
/*
    This function returns the size of the largest BST
    present inside the given Binary Tree.
*/
int largestBST(Node* root) {

    int maxSize = 0;

    // Call helper function
    Info temp = solve(root, maxSize);

    // If the whole tree itself is a BST
    if (temp.isBST) {
        return temp.size;
    }

    // Otherwise return the maximum BST size found
    return maxSize;
}