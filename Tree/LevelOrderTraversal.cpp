// LevelOrderTraversal
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

vector<vector<int>> LevelOrderTraversal(Node* root){
    vector<vector<int>>ans;
    if(!root){
        return ans;
    }

    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        int n = q.size(); // number of nodes at current level
        vector<int> currLevel;
        while(n--){
            Node* temp=q.front();
            q.pop();
            currLevel.push_back(temp->data);
            
            // agar left node  h toh push karo queue mein
            if(temp->left){
                q.push(temp->left);
            }
            // agar right node h toh push karo queue mein
            if(temp->right){
                q.push(temp->right);
            }
        }
        // current level ke nodes ko ans mein push karo
        ans.push_back(currLevel);
    }
    return ans;
}