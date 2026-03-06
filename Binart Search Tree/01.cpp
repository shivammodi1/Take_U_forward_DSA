#includeb<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* insertBST(int val,Node* root){
    if(root==NULL){
        root = new Node(val);
        return root;
    }
    // if value is smaller than root then insert in left subtree
    if(val<root->data){
        root->left = insertBST(val,root->left);
    }
    // if value is greater than root then insert in right subtree
    else{
        root->right = insertBST(val,root->right);
    }
    return root;
}

int main(){
    Node* root = NULL;
    int data;
    while(true){
        cin>>data;
        if(data==-1) break;
        root = insertBST(data,root);
    }

    return 0;
}


// Binary Search Tree
/*
    A binary Seach tree is a speacial tree where 
    # Every node has at most 2 children
    # For Every Node -
        # All the nodes in the left subtree are smaller than the node
        # All the nodes in the right subtree are greater than the node
    # Both the left and right subtrees are also binary search trees
    # The Inorder traversal of a binary search tree is always sorted in increasing order

    # If there is a question to check this tree is sorted or not
       -> Just traverse the tree in Inorder and check the values are in increasing order or not
       -> If sorted then it is a binary search tree otherwise not
*/