#include <bits/stdc++.h>
using namespace std;

string freqSort(string s)
{
    unordered_map<char, int> m; // Step 1: store frequency of each character

    for (int i = 0; i < s.size(); i++)
    {
        m[s[i]]++; // count occurrences of each character
    }

    // Step 2: copy all characters into a vector
    vector<char> chars(s.begin(), s.end());

    // Step 3: custom sort
    sort(chars.begin(), chars.end(), [&](char a, char b)
         {
             if (m[a] != m[b])
             {
                 return m[a] > m[b]; // higher frequency comes first
             }
             return a > b; // if same frequency, sort by character descending
         });

    // Step 4: convert vector back to string
    return string(chars.begin(), chars.end());
}

int main()
{
    string s = "tree";
    string sorted = freqSort(s);
    cout << "Sorted by frequency: " << sorted << endl;
    return 0;
}