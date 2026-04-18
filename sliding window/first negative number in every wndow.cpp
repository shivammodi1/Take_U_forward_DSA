#include <bits/stdc++.h>
using namespace std;


// method 2:
class Solution {
  public:
  
    vector<int> firstNegInt(vector<int>& arr, int k) {
        /*
        APPROACH (Sliding Window + Queue) :

        1. We use two pointers i and j to maintain a window of size k.
        2. Maintain a queue that stores ONLY negative elements of current window.
        3. While expanding window (j):
            - If arr[j] is negative → push into queue.
        4. When window size becomes k:
            - If queue is empty → no negative → push 0 in answer.
            - Else → front of queue is first negative → push it.
        5. Before sliding window:
            - If arr[i] == q.front() → remove it (outdated element).
        6. Slide window: i++, j++

        Time Complexity: O(n)
        Space Complexity: O(k) (in worst case all elements negative)
        */

        int n=arr.size();
        vector<int>ans;
        
        int i=0, j=0;
        queue<int>q;
        
        while(j<n){
            
            // push negative elements
            if(arr[j] < 0){
                q.push(arr[j]);
            }
            
            // window size < k
            if(j-i+1 < k){
                j++;
            }
            
            // window size == k
            else if(j-i+1 == k){
                
                // store answer
                if(q.empty()){
                    ans.push_back(0);
                } else {
                    ans.push_back(q.front());
                }
                
                // remove outgoing element
                if(!q.empty() && arr[i] == q.front()){
                    q.pop();
                }
                
                // slide window
                i++;
                j++;
            }
        }
        
        return ans;
    }
};

// method 1:
// using two loops to find first negative in every window of size k
// time complexity: O(n*k) in worst case when all elements are negative
/*
class Solution {
  public:
  
    vector<int> firstNegInt(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>ans;
        
        for(int i=0; i<=n-k; i++){
            int firstNeg=0;
            for(int j=i; j<i+k; j++){
                if(arr[j] < 0){
                    firstNeg = arr[j];
                    break;
                }
            }
            ans.push_back(firstNeg);
        }
        
        return ans;
    }
};
*/