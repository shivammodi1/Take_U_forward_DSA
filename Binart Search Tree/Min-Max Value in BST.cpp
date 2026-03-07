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

int minValue(Node* root){
    // for min value in BST
    // So the left-most node is min value in BST
    Node *temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxValue(Node* root){
    // for max value in BST
    // So the right-most node is max value in BST
    Node *temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int main(){
    return 0;
}