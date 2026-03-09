#include <bits/stdc++.h>
using namespace std;

/*
Structure of Node in BST
*/
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

/*
Approach for LCA in BST

There are three cases:

Case 1:
If both n1 and n2 are smaller than root,
then LCA lies in the left subtree.

Case 2:
If both n1 and n2 are greater than root,
then LCA lies in the right subtree.

Case 3:
If one node is smaller and the other is greater
(or one equals root), then the current root
is the Lowest Common Ancestor.
*/

class Solution {
public:
    Node* LCA(Node* root, Node* n1, Node* n2) {

        // Base case
        if (root == NULL) {
            return NULL;
        }

        // Case 1: both nodes in left subtree
        if (root->data > n1->data && root->data > n2->data) {
            return LCA(root->left, n1, n2);
        }

        // Case 2: both nodes in right subtree
        if (root->data < n1->data && root->data < n2->data) {
            return LCA(root->right, n1, n2);
        }

        // Case 3: nodes are on different sides
        // so current node is LCA
        return root;
    }
};