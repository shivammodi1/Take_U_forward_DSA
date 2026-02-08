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


int main(){

    Node* root = createNode();

    cout<<"Pre-order traversal of the tree is: "<<endl;
    preOrder(root);

    return 0;
}
