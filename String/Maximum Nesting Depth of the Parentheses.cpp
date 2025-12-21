#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int count = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // Check for opening and closing parentheses
        // Update count and ans accordingly
        if (s[i] == '(')
        {
            count++;
        }
        else if (s[i] == ')')
        {   // Closing parenthesis
            // Update maximum depth before decreasing count
            ans = max(ans, count);
            count--;
        }
        else
        { 
            // For other characters, just update the maximum depth
            ans = max(ans, count);
        }
    }
    return ans;
}

// output the maximum nesting depth for a sample input
// Example usage
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3

int main()
{
    string s = "(1+(2*3)+((8)/4))+1";
    int depth = maxDepth(s);
    cout << "Maximum Nesting Depth: " << depth << endl;
    return 0;
}