#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


bool isSame(Node *root1, Node* root2){
    // dono tree empty hai
    if(!root1 && !root2){
        return 1;
    }

    // ek tree empty hai aur dusra nahi
    if(!root1 && root2){
        return 0;
    }
    // ek tree empty hai aur dusra nahi
    if(root1 && !root2){
        return 0;
    }

    // dono tree ke root ka data alag hai
    if(root1->data != root2->data){
        return 0;
    }

    // ab left subtree aur right subtree check karenge
    return isSame(root1->left,root2->left) && isSame(root1->right, root2->right);
}

int main(){
    return 0;
}