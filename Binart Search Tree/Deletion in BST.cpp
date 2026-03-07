#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Appraoch:
// 1. First we will search for the node to be deleted in the BST
// 2. Once we find the node, we will check for the three cases
//   a. No child: In this case, we will simply delete the node and return null
//   b. One child: In this case, we will replace the node with its child and delete the node
//   c. Two children: In this case, we will find the rightmost node in the left subtree of the node to be deleted and replace the node with that rightmost node. Then we will delete the rightmost node from the left subtree.
//       This is because the rightmost node in the left subtree will be the largest node in the left subtree and will be less than the node to be deleted, so it will maintain the properties of the BST.
// Time complexity: O(h) where h is the height of the tree
// Space complexity: O(h) where h is the height of the tree (recursive stack space)s

// delete a node in BST
Node *deleteNode(Node *root, int key)
{
    if (!root)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        // case 1. No child
        // delete the node and return null
        if (!root->left && !root->right)
        {
            delete root;
            return NULL;
        }

        // case 2. One child
        // woh child left ho ya right, usko root ke jagah le aao
        if (root->left == NULL)
        {
            Node *tmp = root->right;
            delete root;
            return tmp;
        }

        if (root->right == NULL)
        {
            Node *tmp = root->left;
            delete root;
            return tmp;
        }

        // case 3. Two children
        // left me jao phir right most element se deleted node ke sath replace kar do
        Node *tmp = root->left;
        while (tmp->right)
        {
            tmp = tmp->right;
        }
        root->data = tmp->data;
        root->left = deleteNode(root->left, tmp->data);
        return root;
    }
    return root;
}

int main()
{
    return 0;
}