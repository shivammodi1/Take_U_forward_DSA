#include<bits/stdc++.h>
using namespace std;

/*
Problem: Find path from Root node to given node X.

Example Tree:

              1
            /   \
           2     3
          / \
         4   5

If x = 5
Output: [1, 2, 5]


-------------------- APPROACH --------------------

1. DFS (Depth First Search) traversal use karenge.
2. Har visited node ko path vector me push karenge.
3. Agar current node ka data == x ho jaye,
   to true return kar denge (path mil gaya).
4. Agar left ya right subtree me x mil jaye,
   to true return karenge.
5. Agar kahin bhi x nahi mila,
   to current node ko path se pop karenge (Backtracking).
6. Finally path vector me root → x ka path hoga.

Time Complexity: O(N)
Space Complexity: O(H)  (H = height of tree)

--------------------------------------------------
*/

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool solve(Node* root, int x, vector<int> &path){
    if(root == NULL) 
        return false;

    // Step 1: Add current node to path
    path.push_back(root->data);

    // Step 2: Check if current node is target
    if(root->data == x) 
        return true;

    // Step 3: Check left or right subtree
    if(solve(root->left, x, path) || 
       solve(root->right, x, path))
        return true;

    // Step 4: Backtracking (remove current node)
    path.pop_back();
    return false;
}

vector<int> rootToNodePath(Node* root, int x){
    vector<int> path;
    solve(root, x, path);
    return path;
}

int main(){
    return 0;
}