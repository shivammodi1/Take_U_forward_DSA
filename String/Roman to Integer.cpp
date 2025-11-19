#include <bits/stdc++.h>
using namespace std;

// method 1 using unordered_map
int romanToInt(string s)
{
    int res = 0;

    // Map of Roman numerals to their integer values
    unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    // Iterate through the string, except the last character
    for (int i = 0; i < s.size() - 1; i++)
    {
        // Subtract if current numeral is less than the next
        if (roman[s[i]] < roman[s[i + 1]])
        {
            res -= roman[s[i]];
        }
        else
        {
            // Otherwise, add the current value
            res += roman[s[i]];
        }
    }

    // Add the value of the last character
    return res + roman[s.back()];
}

// method 2 using if else nad vector
int romanToInt(string s)
{
    vector<int> Roman;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'I')
        {
            Roman.push_back(1);
        }
        else if (s[i] == 'V')
        {
            Roman.push_back(5);
        }
        else if (s[i] == 'X')
        {
            Roman.push_back(10);
        }
        else if (s[i] == 'L')
        {
            Roman.push_back(50);
        }
        else if (s[i] == 'C')
        {
            Roman.push_back(100);
        }
        else if (s[i] == 'D')
        {
            Roman.push_back(500);
        }
        else if (s[i] == 'M')
        {
            Roman.push_back(1000);
        }
    }
    int sum = 0;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (Roman[i] >= Roman[i + 1])
        {
            sum += Roman[i];
        }
        else
        {
            sum -= Roman[i];
        }
    }

    return sum + Roman[Roman.size() - 1];
}

int main()
{
    string s = "MCMXCIV";
    int result = romanToInt(s);

    // Print the result
    cout << "Integer value: " << result << endl;

    return 0;
}