#include<bits/stdc++.h>
using namespace std;

/*
LPS (Longest Prefix which is also Suffix)

Definition:
At any index i, LPS[i] stores the length of the longest proper prefix
which is also a suffix for substring pattern[0...i].

Example:
Pattern: A B A B C
LPS:     0 0 1 2 0

Approach:
We use two pointers:
1. i   -> current index (starts from 1)
2. len -> length of previous longest prefix-suffix (starts from 0)

Rules:
1. If pattern[i] == pattern[len]:
      - Increase len
      - Set lps[i] = len
      - Move both pointers (i++, len++)

2. If mismatch occurs:
   a) If len != 0:
         - Update len = lps[len - 1]
         - Do NOT move i (recheck same i)

   b) If len == 0:
         - Set lps[i] = 0
         - Move i++

Time Complexity: O(n)
*/

vector<int> LPS(string pattern){
    int n = pattern.size();

    // LPS array initialized with 0
    vector<int> lps(n, 0);

    int len = 0;  // length of previous longest prefix-suffix
    int i = 1;    // start from index 1

    while(i < n){
        // Case 1: characters match
        if(pattern[i] == pattern[len]){
            len++;              // increase prefix-suffix length
            lps[i] = len;       // store in LPS array
            i++;                // move forward
        }
        else{
            // Case 2: mismatch
            if(len != 0){
                // fallback using previous LPS value
                len = lps[len - 1];

                // NOTE: i is NOT incremented here
                // we recheck with updated len
            }
            else{
                // no prefix-suffix match
                lps[i] = 0;
                i++;            // move forward
            }
        }
    }

    return lps; // return the LPS array
}

// if the question is to find the longest prefix which is also a suffix for the entire string, we can simply return lps[n-1]
// return lps[n-1]; // longest prefix-suffix for the entire string

int main(){
    string pattern = "ABABC";
    vector<int> lps = LPS(pattern);
    for(int i=0; i<lps.size(); i++){
        cout << lps[i] << " ";
    }

    return 0;
}