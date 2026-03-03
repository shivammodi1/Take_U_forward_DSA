// Maximum Non-Adjacent Nodes Sum
// Problem: Binary Tree se aisa subset choose karo
// jisme koi bhi 2 directly connected (parent-child)
// nodes select na ho aur sum maximum ho.

#include <bits/stdc++.h>
using namespace std;

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    /*
        solve() function har node ke liye
        ek pair return karega:
        
        first  -> include current node ka maximum sum
        second -> exclude current node ka maximum sum
    */
    pair<int,int> solve(Node* root){
        
        // Base Case:
        // Agar node NULL hai to include aur exclude dono 0
        if(root == NULL)
            return {0, 0};
        
        // Left subtree solve karo
        pair<int,int> left = solve(root->left);
        
        // Right subtree solve karo
        pair<int,int> right = solve(root->right);
        
        /*
            1️⃣ Include current node
            
            Agar current node include kiya
            to uske children include nahi kar sakte.
            
            To hum children ke exclude wale values lenge.
        */
        int include = root->data 
                      + left.second 
                      + right.second;
        
        
        /*
            2️⃣ Exclude current node
            
            Agar current node exclude kiya
            to children include ya exclude dono me se
            jo maximum hoga woh le sakte hain.
        */
        int exclude = max(left.first, left.second)
                      + max(right.first, right.second);
        
        return {include, exclude};
    }
  
    int getMaxSum(Node *root) {
        
        // Root ke liye include/exclude nikal lo
        pair<int,int> ans = solve(root);
        
        // Final answer dono me se maximum hoga
        return max(ans.first, ans.second);
    }
};