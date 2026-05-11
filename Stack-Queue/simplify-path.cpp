#include <bits/stdc++.h>
using namespace std;


/*
    Question: https://leetcode.com/problems/simplify-path/
    Rules: 1. A single dot '.' refers to the current directory.
           2. A double dot '..' moves the directory up a level.
           3. Multiple consecutive slashes '//' are treated as a single slash '/'.

    Approach: 
            1. Split the input path by '/' and store the parts in a vector.
            2. Use a stack to process the parts:
                - If the part is empty or '.', ignore it.
                - If the part is '..', pop from the stack if it's not empty.
                - Otherwise, push the part onto the stack.
            3. Check if the stack is empty. If it is, return "/".
            4. If the stack is not empty, pop all elements and store them in a temporary vector.
            5. Reverse the temporary vector to get the correct order of directories.
            6. Concatenate the directories from the temporary vector, prefixing each with a '/', to form the final simplified path.

    Time Complexity: O(n), where n is the length of the input path.
    Space Complexity: O(n), in the worst case, if all parts are valid directory names
    
*/

class Solution {
public:
    string simplifyPath(string path) {

        vector<string> arr;

    // stringstream treats a string like a stream (just like cin), so you can extract parts of it one by one.
       stringstream ss(path);
        string token;

        while(getline(ss, token, '/')) {
            arr.push_back(token);
        }

        stack<string> st;

        for(int i = 0; i < arr.size(); i++) {

            if(arr[i] == "" || arr[i] == ".") {
                continue;
            }

            else if(arr[i] == "..") {

                if(!st.empty()) {
                    st.pop();
                }
            }

            else {
                st.push(arr[i]);
            }
        }

        if(st.empty()) {
            return "/";
        }

        vector<string> temp;

        while(!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        string ans = "";

        for(string x : temp) {
            ans += "/" + x;
        }

        return ans;
    }
};