#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // this for storing their index at there ASIIC index
        vector<int>indexS(256,-1); 
        vector<int>indexT(256,-1);

        for(int i=0;i<s.size();i++){
            // at the same place if their value is different than false
            if(indexS[s[i]] != indexT[t[i]]){
                return false;
            }
            // updating the index 
            indexS[s[i]]=i;
            indexT[t[i]]=i;
        }

        return true;
    }
};

int main(){
    string s = "egg";
    string t = "add";

    Solution sol;
    bool ans = sol.isIsomorphic(s,t);

    if(ans){
        cout<<"The strings are isomorphic."<<endl;
    }else{
        cout<<"The strings are not isomorphic."<<endl;
    }

    return 0;
}