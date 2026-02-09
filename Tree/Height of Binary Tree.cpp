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

int Height(Node* root){
    if(!root){
        return 0;
    }

    int left = Height(root->left);
    int right = Height(root->right);

    return 1 + max(left, right);
}

// tree structure
//                       1
//                     /   \
//                    2     3
//                  /   \   
//                 4     5

//             Height of the above tree is 3

int main(){
    return 0;
}