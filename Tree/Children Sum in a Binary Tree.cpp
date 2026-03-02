// Children Sum in a Binary Tree
// In this we need to check if root->data == left->data + right->data for every node in the tree
// If it is true for every node then we return true else false
// example: 
//        10
//       /  \
//      8    2
//     / \    \
//    3   5    2
// In this tree 10 == 8 + 2 and 8 == 3 + 5 and 2 == 0 + 2 so we return true

bool isSumProperty(Node* root){
    if(root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return true; // Null or leaf node satisfies the property
    }
    int leftNode=0, rightNode=0;
    if(root->left != nullptr) {
        leftNode = root->left->data;
    }
    if(root->right != nullptr) {
        rightNode = root->right->data;
    }
    if(root->data == leftNode + rightNode && isSumProperty(root->left) && isSumProperty(root->right)) {
        return true;
    }
    return false;
}

// Approach:
// 1. if root is null or it is leaf node then we return true
// 2. if root->left is not null then store in leftNode else 0
// 3. if root->right is not null then store in rightNode else 0
// 4. if root->data == leftNode + rightNode and isSumProperty(root->left) and isSumProperty(root->right) then return true else false

int main(){
    return 0;
}