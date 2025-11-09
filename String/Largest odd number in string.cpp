#include <bits/stdc++.h>
using namespace std;

// Function to find the largest odd number in the string
// by checking from the end of the string
// and returning the substring up to the first odd digit found
// Time Complexity: O(n), where n is the length of the string
// Space Complexity: O(1) for variables, O(n) for the output string


string largestOddNumber(string num)
{
    string ans = "";
    for (int i = num.length() - 1; i >= 0; i--)
    {
        // checking from last digit to first if there is any odd so 
        // from start to that odd digit we will return the substring
        if ((num[i] - '0') % 2 != 0)
        {
            // odd found
            ans = num.substr(0, i + 1);
            return ans;
        }
    }
    return ans;
}

int main()
{
    string num;
    cout << "Enter a numeric string: ";
    cin >> num;
    string result = largestOddNumber(num);
    if (result.empty())
        cout << "No odd number found in the string." << endl;
    else
        cout << "The largest odd number in the string is: " << result << endl;
    return 0;
}   