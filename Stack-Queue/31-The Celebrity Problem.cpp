// The Celebrity Problem
// Toh in this problem, we have to find the celebrity in a party.
// A celebrity is a person who is known by everyone but does not know anyone at the party.
// We are given a matrix M where M[i][j] is 1 if the ith person knows the jth person, and 0 otherwise.
// We have to find the index of the celebrity if there is one, or return -1 if there is no celebrity.

// input: M = [[0,1,0],[0,0,0],[0,1,0]]
// output: 1
// Explanation: The person at index 1 is the celebrity because everyone knows them but they do not know anyone else.


#include<bits/stdc++.h>
using namespace std;

// method 1 -> brute force
// time complexity -> O(N^2)
int findCelebrity(vector<int>& M,int n){
    vector<int>knowMe(n,0);
    vector<int>IKnow(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j && M[i][j]==1){
                knowMe[j]++;
                IKnow[i]++;
            }
        }
    }

    // for celebrity,
    // knowMe should be n-1 and IKnow should be 0
    for(int i=0;i<n;i++){
        if(knowMe[i]==n-1 && IKnow[i]==0){
            return i;
        }
    }
    return -1;
}

// method 2 -> using stack
// time complexity -> O(N)
int findCelebrity(vector<int>& M){
    int n = M.size();
    stack<int>s;
    for(int i=0;i<n;i++){
        s.push(i);
    }

    while(s.size()>1){
        int Person1 = s.top();
        s.pop();
        int Person2 = s.top();
        s.pop();

        if(M[Person1][Person2] == 1){
            // agar person1 knows person2, toh person1 cannot be a celebrity, 
            // toh push person2
            s.push(Person2);
        }
        else{
            s.push(Person1);
        }
    }
    int Celebrity = s.top();
    // check if the celebrity is a real celebrity
    for(int i=0;i<n;i++){
        // agar koi bhi celebrity ke alawa kisi bhi person ko celebrity janta hai ya celebrity kisi ko janta hai, toh return -1
        if(i!=Celebrity && (M[Celebrity][i] == 1 || M[i][Celebrity] == 0)){
            return -1;
        }
    }
    return Celebrity;
}

// method 3 -> using two pointers
// time complexity -> O(N)
// pointer1 at 0 and pointer2 at n-1
int findCelevrity(vector<int>& M){
    int n = M.size();
    int top=0;
    int down = n-1;
    while(top<down){
        if(M[top][down]==1){
            // agar top person down person ko janta hai, toh top person cannot be a celebrity, toh top++
            top++;
        }
        else if(M[down][top]==1){
             // agar down person top person ko janta hai, toh down person cannot be a celebrity, toh down--
                down--;
        }else{
            top++;
            down--;
        }
    }
    int Celebrity = top;
    // check if the celebrity is a real celebrity
    for(int i=0;i<n;i++){
        if(i!=Celebrity && (M[Celebrity][i] == 1 || M[i][Celebrity]==0)){
            return -1;
        }
    }
    return Celebrity;
}

int main(){
    return 0;
}