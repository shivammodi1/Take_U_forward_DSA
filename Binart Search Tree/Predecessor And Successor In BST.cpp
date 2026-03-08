#include <bits/stdc++.h>
using namespace std;

/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    void InOrder(Node *root, vector<Node *> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        InOrder(root->left, ans);
        ans.push_back(root);
        InOrder(root->right, ans);
    }

    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> ans;
        vector<Node *> res;

        if (root == NULL)
        {
            res.push_back(NULL);
            res.push_back(NULL);
            return res;
        }

        InOrder(root, ans);

        Node *mini = NULL;
        Node *maxi = NULL;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i]->data < key)
            {
                mini = ans[i];
            }
        }
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i]->data > key)
            {
                maxi = ans[i];
                break;
            }
        }

        res.push_back(mini);
        res.push_back(maxi);
        return res;
    }
};

// method 2 : Using Preorder Traversal
// 1. check root ka data key se chota hain AND root ka data greater ho pred ke data se
//    a. than update update pred
//     if(root->data < key && root->data > pred->data){
//          pred = root;
//      }
// 2. check root ka data key se bada hain AND root ka data less ho succ ke data se
//    a. than update update succ
//     if(root->data > key && root->data < succ->data){
//          succ = root;
//      }
// 3. Than Go left and right subtree

void preOrder(Node* root, Node *&pred, Node *&succ, int key)
{
    if(!root){
        return ;
    }
    // Node check
    if(root->data < key && (pred==NULL || root->data > pred->data)){
        pred = root;
    }  
    if(root->data > key && (succ==NULL || root->data < succ->data)){
        succ = root;
    }
    //left 
    preOrder(root->left,pred,succ,key);
    //right
    preOrder(root->right,pred,succ,key);
}

vector<Node*> findPreSuc(Node *root, int key)
{
    vector<Node*> ans;
    Node* pred = NULL;
    Node* succ = NULL;
    preOrder(root,pred,succ,key);
    ans.push_back(pred);
    ans.push_back(succ);
    return ans;
}


int main()
{
    return 0;
}