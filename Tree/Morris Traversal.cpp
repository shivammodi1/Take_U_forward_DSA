// explanation is .md file

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

void MorrisTraversal(Node* root){
    // Base Case
    if(root == NULL) return;

    // current pointer
    Node* current = root;

    while(current != NULL){

        // Case 1: left NULL
        if(current->left == NULL){
            cout << current->data << " ";
            current = current->right;
        }

        else{

            // find inorder predecessor
            Node* pred = current->left;

            while(pred->right != NULL && pred->right != current){
                pred = pred->right;
            }

            // create temporary link
            if(pred->right == NULL){
                pred->right = current;
                current = current->left;
            }

            // link already exists → remove it
            else{
                pred->right = NULL;
                cout << current->data << " "; // print it after removing the link
                current = current->right; // than move to right subtree
            }
        }
    }
}

int main(){

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    MorrisTraversal(root);

    return 0;
}