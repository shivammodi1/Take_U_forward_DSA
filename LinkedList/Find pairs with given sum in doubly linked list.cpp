#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
    vector<int> values;
    Node* curr = head;
    while(curr != NULL){
        values.push_back(curr->data);
        curr = curr->next;
    }
    vector<pair<int,int>> result;
    // two pointer approach
    int st=0;
    int end=values.size()-1;
    while(st<end){
        int sum = values[st] + values[end];
        if(sum == target){
            // found a pair
            result.push_back({values[st],values[end]});
            st++;
            end--;
        }else if(sum > target){
            // need to decrease sum
            end--;
        }else{
            // need to increase sum
            st++;
        }
    }
    return result;

}

int main(){

}

// Input: head = [1, 2, 4, 5, 6, 8, 9], target = 7
// Output: [[1, 6], [2, 5]]
// Explanation:
// 1 + 6 = 7 and 2 + 5 = 7 are the valid pairs.