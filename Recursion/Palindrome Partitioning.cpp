#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end)
{

    while (start <= end)
    {
        if (str[start] != str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void Helper(string s,int index,vector<vector<string>> &result,vector<string> &currPartition,int n){
    if(index==n){
        result.push_back(currPartition);
        return;
    }

    for(int i=index;i<n;i++){
        if(isPalindrome(s,index,i)){
            // Choose the palindrome substring
            string palin = s.substr(index,i-index+1); // substring from index to i where i-index+1 is length and index is starting point
            currPartition.push_back(palin);
            Helper(s,i+1,result,currPartition,n);
            currPartition.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> result;
    vector<string> currPartition;
    int n = s.size();
    
    Helper(s,0,result,currPartition,n);
    return result;
    
}

int main()
{
    return 0;
}


// recursion tree
// Helper(index=0, curr=[])
// │
// ├── Choose "a"  (0..0)
// │   Helper(index=1, curr=["a"])
// │   │
// │   ├── Choose "a"  (1..1)
// │   │   Helper(index=2, curr=["a","a"])
// │   │   │
// │   │   ├── Choose "b"  (2..2)
// │   │   │   Helper(index=3, curr=["a","a","b"])
// │   │   │   │
// │   │   │   └── Choose "b"  (3..3)
// │   │   │       Helper(index=4, curr=["a","a","b","b"])
// │   │   │       → ✅ store ["a","a","b","b"]
// │   │   │
// │   │   └── Choose "bb" (2..3)
// │   │       Helper(index=4, curr=["a","a","bb"])
// │   │       → ✅ store ["a","a","bb"]
// │   │
// │   └── (skip "ab" → not palindrome)
// │
// ├── Choose "aa" (0..1)
// │   Helper(index=2, curr=["aa"])
// │   │
// │   ├── Choose "b" (2..2)
// │   │   Helper(index=3, curr=["aa","b"])
// │   │   │
// │   │   └── Choose "b" (3..3)
// │   │       Helper(index=4, curr=["aa","b","b"])
// │   │       → ✅ store ["aa","b","b"]
// │   │
// │   └── Choose "bb" (2..3)
// │       Helper(index=4, curr=["aa","bb"])
// │       → ✅ store ["aa","bb"]
// │
// └── (skip "aab", "aabb" → not palindrome)
