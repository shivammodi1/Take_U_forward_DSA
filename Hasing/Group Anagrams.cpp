#include <bits/stdc++.h>
using namespace std;

// question
// Given an array of strings, group anagrams together.
// Example:
// Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// approach:
// Jo bhi same anagram ka usko 1 group me rakhna hain
// 1. so for storing we will use map with string and vector<string>
// 2. Iterate karo over the array of strings
//   - a. sort the current string
//   - b. insert that sorted string along with orinal value of string nside map
//         aet->[eat,tea,ate]
// 3. create vector<vector<string>> ans
// 4. abb iterate over the map and push second value of map inside ans
// 5. return ans

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    // step1: create map of string and vector
    unordered_map<string, vector<string>> mp;
    // step2. iterate karo strs me orr each string ko sort ko
    //        - eat -> aet
    //        - tea -> aet toh aet ko map me dalo with orinal string ke sath
    //  like aet -> [eat,tea,ate]
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        mp[s].push_back(strs[i]);
    }

    vector<vector<string>> ans;
    // step3:
    // abb iterate over map and push it.second in 2d array
    for (auto it : mp)
    {
        vector<string> tmp = it.second;
        ans.push_back(tmp);
    }
    return ans;
}

int main()
{
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}