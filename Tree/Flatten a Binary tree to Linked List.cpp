// Flatten a Binary tree to Linked List
// Given the root of a binary tree, flatten the tree into a "linked list":
// example :   1
//            / \
//           2   5
//          / \   \
//         3   4   6
// output : 1
//           \
//            2
//              \
//               3
//                 \
//                  4
//                    \
//                     5
//                      \
//                       6

// Algorithm :
// 1. In this without using extra space we will solve this problem by inplace modification.
// 2. Use a curr pointer to traverse the tree starting from the root.
// 3. While curr is exist,
//    a. If curr->left is null than move curr to curr->right.
//    b. Else left subtree is exist than,
//       i. Find the left subtree's right most node and store in prev pointer.
//       ii. Make a link between prev->right and curr->right.
//       iii. Make a link between curr->right and curr->left.
//       iv. Make curr->left as null.
//       v. Move curr to curr->right.
// 4. Finally we will get the flattened tree in the form of linked list.
// Time Complexity : O(n) where n is the number of nodes in the tree.
// Space Complexity : O(1) as we are not using any extra space.


//code:
void flatten(Node* root){
    Node* curr = root; // step 1.
    while(curr){ // step 2.
        // step 3.a.
        if(curr->left==NULL){
            curr = curr->right;
        }
        else{ // step 3.b.
            // step 3.b.i.
            Node* prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }
            prev->right = curr->right; // step 3.b.ii.
            curr->right = curr->left; // step 3.b.iii.
            curr->left = NULL; // step 3.b.iv.
            curr = curr->right; // step 3.b.v.
        }
    }
}