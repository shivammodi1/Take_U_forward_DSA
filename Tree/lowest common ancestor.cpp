//  Lowest Common Ancestor of a Binary Tree
// example:- LCA(4,7)  tree:-    1
//                             /   \
//                            2     3
//                           / \
//                          4   5
//                         /   / \
//                        6   7   8
// Output: 2

// Approach:-
// 1. If current node is not null and matches either p or q, return current node.
// 2. Recursively search for p and q in the left and right subtrees.
// 3. if both left and right are null, return null.
// 4. If one of them is null, return the non-null node.

#include<bits/stdc++.h>
using namespace std;


int main(){
    return 0;
}