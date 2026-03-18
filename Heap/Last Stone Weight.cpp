#include<bits/stdc++.h>
using namespace std;

// So in this question array given hain stones ka where arr[i] shows the weight of ith stone.
// In each turn hame 2 max weight ke stone ko lene hain or smash krna hain.
// agar dono same hain both smash.
// agar dono different hain to smaller stone smash hoga or bigger stone ka weight update hoga as bigger - smaller.
// at the end hame last stone ka weight return krna hain or agar no stone left hain to return 0.

// example: stones = [2,7,4,1,8,1]
// 1st -> 7 and 8 smash, 1 stone left with weight 1-> [2,4,1,1,1]
// 2nd -> 2 and 4 smash, 1 stone left with weight 2-> [2,1,1,1]
// 3rd -> 1 and 2 smash, 1 stone left with weight 1-> [1,1,1]
// 4th -> 1 and 1 smash, no stone left-> [1]
// 5th -> 1 and 1 smash, no stone left-> []
// output: 1
// example: stones = [1]
// output: 1


int lastStoneWeight(vector<int>& st){
    int n = st.size();

    if(n == 0) return 0;
    if(n == 1) return st[0];

    priority_queue<int>pq;
    for(int i = 0; i < n; i++){
        pq.push(st[i]);
    }

    // hame 1 item left hone tak smash krna hain
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        if(first != second){
            pq.push(abs(first - second));
        }
    }

    if(pq.empty()) return 0;
    return pq.top();

}

int main(){
    return 0;
}