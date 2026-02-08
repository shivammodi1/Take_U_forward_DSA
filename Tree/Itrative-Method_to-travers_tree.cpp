#include<bits/stdc++.h>
using namespace std;


// iterative method to traverse tree
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

// Iterative Preorder Traversal
// phale stack me right child push karenge 
// then left child push karenge taki left child phale pop ho
vector<int> preOrder(Node* root){
    vector<int> ans;
    if(!root){
        return ans;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        ans.push_back(node->data);

        if(node->right){
            st.push(node->right);
        }
        if(node->left){
            st.push(node->left);
        }
    }
    return ans;

}

// Iterative Inorder Traversal
// Idea:
// • Left side ke sab nodes stack me daalte jao
// • Jab left khatam ho:
//     • stack se pop karo
//     • usko print karo
//     • right pe move karo
vector<int> inOrder(Node* root){
    vector<int> ans;
    stack<Node*> st;
    Node* node = root;

    while(true){
        if(node){
            // left child ko stack me push karenge taki left child phale pop ho
            st.push(node);
            node = node->left;
        }
        else{
            //  stack khali hai to loop se bahar nikal jao
            if(st.empty()){
                break;
            }
            // stack me se node ko pop karenge aur uska data ans me push karenge
            node = st.top();
            st.pop();
            ans.push_back(node->data);
            // right child ko stack me push karenge taki right child phale pop ho
            node = node->right;
        }
    }
    return ans;
}

// Iterative Postorder Traversal
// Idea:
// • Stack me nodes ko daalte jao
// traverse karte waqt left child ko pehle push karo, phir right child ko push karo
// taki right child phale pop ho
// last me array ko reverse karna padega taki postorder traversal mile
vector<int> postOrder(Node* root){
    vector<int>ans;
    if(!root){
        return ans;
    }

    stack<Node*> st;
    st.push(root);

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        ans.push_back(temp->data);
        if(temp->left){
            st.push(temp->left);
        }
        if(temp->right){
            st.push(temp->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
