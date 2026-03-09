#include <bits/stdc++.h>
using namespace std;

// Flatten BST to sorted list
//           6
//         /   \
//        5     9
//       /     / \
//      4     8   10
// output:linked list: 4->5->6->8->9->10

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

void Inorder(Node* root,Node* &tmp){
    if(!root){
        return;
    }
    // left subtree
    Inorder(root->left,tmp);
    // create new node in right of tmp and move tmp to right
    tmp->right = new Node(root->data);
    tmp=tmp->right;
    // right subtree
    Inorder(root->right,tmp);
}

Node *flattenBST(Node *root)
{
    // Appraoch:
    // 1. created dummy node tmp and head point to tmp
    Node* tmp = new Node(-1);
    Node* head = tmp;
    //2. abb Inorder traversal krke keval tmp ke right me node ko add krte jao
    Inorder(root, tmp);
    // return head->right as head is pointing to dummy node
    return head->right;
}

int main()
{
    return 0;
}