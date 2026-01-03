// The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
// By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
// "123" "132" "213" "231" "312" "321"
// Given n and k, return the kth permutation sequence.
// Example 1:
// Input: n = 3, k = 3
// Output: "213"

#include <bits/stdc++.h>
using namespace std;

// Method 1: Generate all permutations and return k-1 th indexed permutation
// Time Complexity: O(n*n!)
// Space Complexity: O(n!)
// It will give TLE for large n
void Permute(string &num,int index,vector<string>& result){
    if(index==num.size()){
        result.push_back(num);
        return;
    }

    for(int i=index;i<num.size();i++){
        swap(num[index],num[i]);
        Permute(num,index+1,result);
        swap(num[index],num[i]);
    }
}

string getPermutation(int n, int k)
{
    string num;
    for(int i=1;i<=n;i++){
        num+=to_string(i);
    }

    vector<string> result;
    int index = 0;
    Permute(num,index,result);
    // sort the result to get lexicographical order
    sort(result.begin(),result.end());
    return result[k-1]; // k-1 for 0 based indexing
}


// Method 2: Optimal Approach using Factorial Number System
// Time Complexity: O(n^2)

int main()
{
    return 0;
}