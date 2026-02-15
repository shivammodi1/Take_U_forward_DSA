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

// hame tree ko verticallt order me print krna hain
// agar koi node overlap kr rahe hain to smaller node ko pehle print krna hain
//                           1
//                         /   \
//                        2     3
//                       / \   / \
//                      4   5 6   7
// output: 4 2 1 5 6 3 7
//                                  4
//                                  2
//                                  1 5 6
//                                  3
//                                  7

vector<vector<int>> verticalOrder(Node* root){
    vector<vector<int>> ans;
    if(!root){
        return ans;
    }

    map<int,map<int,multiset<int>>> nodes; // vertical, level, node values
    queue<pair<Node*, pair<int,int>>> q; // node, vertical, level
    q.push({root, {0,0}}); // root node, vertical = 0, level = 0

    while(!q.empty()){
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int vertical = p.second.first;
        int level = p.second.second;

        nodes[vertical][level].insert(node->data);

        if(node->left){
            q.push({node->left, {vertical - 1, level + 1}});
        }
        if(node->right){
            q.push({node->right, {vertical + 1, level + 1}});
        }
    }

    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    
}

int main(){
    return 0;
}