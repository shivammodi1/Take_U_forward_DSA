#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *bottom;

    Node(int val)
    {
        data = val;
        next = NULL;
        bottom = NULL;
    }
};

Node *flatten(Node *root)
{
    // my Approach is using vector to store all the elements of linked list
    // then sort the vector and create a new linked list from sorted vector
    if(!root){
        return NULL;
    }
    Node *temp = root;
    vector<int>ans;

    // traverse the linked list
    while(temp){
        // traverse the bottom linked list
        Node *bot = temp;
        while(bot){
            // store the data in vector
            ans.push_back(bot->data);
            bot = bot->bottom;
        }
        temp = temp->next;
    }
    // sort the vector
    sort(ans.begin(), ans.end());
    Node *newHead = new Node(-1);
    Node *curr = newHead;
    // create new linked list from sorted vector
    for(int i=0; i<ans.size(); i++){
        Node *newNode = new Node(ans[i]);
        curr->bottom = newNode;
        curr = curr->bottom;
    }
    return newHead->bottom;
}

int main()
{
    return 0;
}