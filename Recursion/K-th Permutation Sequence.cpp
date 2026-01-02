// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123" "132" "213" "231" "312" "321"
// Given n and k, return the kth permutation sequence.
// Example 1:
// Input: n = 3, k = 3
// Output: "213"

#include <bits/stdc++.h>
using namespace std;

void Permute(vector<string>& num,int index,string &curr,vector<int>& result){
    
}

string getPermutation(int n, int k)
{
    vector<string> num;
    for(int i=1;i<=n;i++){
        num.push_back(to_string(i));
    }

    vector<string> result;
    int index = 0;
    string curr="";
    Permute(num,index,curr,result);
}

int main()
{
    return 0;
}