#include<bits/stdc++.h>
using namespace std;

// Diameter of Binary Tree
// longest path between any two nodes in a tree
// path may or may not pass through the root

int height(Node* root,int &maxiDia){
    if(!root){
        return 0;
    }

    int LH = height(root->left,maxiDia);
    int RH = height(root->right,maxiDia);
    maxiDia = max(maxiDia,LH+RH);

    return 1+max(LH,RH);
}

int diameterOfBT(Node* root){
   int maxiDia = 0;
   height(root,maxiDia);
   return maxiDia;
}

int main(){
    return 0;
}