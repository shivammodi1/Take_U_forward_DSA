// Input: s = "the sky is blue"
// Output: "blue is sky the"

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();
    string ans = "";

    // Step 1: Reverse the entire string
    // Example: "the sky is blue" → "eulb si yks eht"
    reverse(s.begin(), s.end());

    // Step 2: Traverse each character to rebuild words in correct order
    for (int i = 0; i < n; i++)
    {
        string word = "";

        // Step 3: Extract each word (characters until a space)
        while (i < n && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        // Step 4: Reverse the current word to restore its correct order
        // Example: "eulb" → "blue"
        reverse(word.begin(), word.end());

        // Step 5: Add the word to the final string (skip empty ones)
        if (word.length() > 0)
        {
            ans += " " + word; // Add a space before each word
        }
    }

    // Step 6: Remove the leading space added at the beginning
    return ans.substr(1);
}

int main()
{
    string s = "the sky is blue";
    string result = reverseWords(s);
    cout << result << endl;  // Output: "blue is sky the"
    return 0;
}