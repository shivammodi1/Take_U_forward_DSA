#include<bits/stdc++.h>
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

// function to create a new node until user enters -1
Node* createNode(){
    int val;
    cout<<"Enter value (-1 for NULL): ";
    cin>>val;

    if(val==-1){
        return NULL;
    }

    Node* newNode = new Node(val);

    cout<<"Enter left child of "<<val<<endl;
    newNode->left = createNode();

    cout<<"Enter right child of "<<val<<endl;
    newNode->right = createNode();

    return newNode;
}

// print the tree in pre-order traversal
// NLR
void preOrder(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

// Inorder -> LNR
void inOrder(Node* root){
    if(!root){
        return NULL;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

//PostOrder
// LRN
void postOrder(Node* root){
    if(!root){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int main(){

    Node* root = createNode();

    cout<<"Pre-order traversal of the tree is: "<<endl;
    preOrder(root);

    return 0;
}
