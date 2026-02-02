// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Approach:
// 1. we can use stack to keet track of the asteroids
// 2. If the element is positive we can push it to the stack
// 3. if element is negative we can check the top of the stack
//       1. if top is positive and current element is negative and abs(current) > top
//            ->  we can pop the top of the stack
//       2. if top is positive and current element is negative and abs(current) == top
//            ->  we can pop the top of the stack and ignore current element
//       3. if top is positive and current element is negative and abs(current) < top
//            ->  we can ignore current element
//      4. if top is negative we can push the current element to the stack
// 4. Finally we can return the elements in the stack as result


// Input: asteroids = [5,10,-5]
// Output: [5,10]
// Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
// Example 2:

// Input: asteroids = [8,-8]
// Output: []
// Explanation: The 8 and -8 collide exploding each other.

// Approach:
// 1. we can use stack to keet track of the asteroids
// 2. If the element is positive we can push it to the stack
// 3. if element is negative we can check the top of the stack
//       1. if top is positive and current element is negative and abs(current) > top
//            ->  we can pop the top of the stack
//       2. if top is positive and current element is negative and abs(current) == top
//            ->  we can pop the top of the stack and ignore current element
//       3. if top is positive and current element is negative and abs(current) < top
//            ->  we can ignore current element
//      4. if top is negative we can push the current element to the stack
// 4. Finally we can return the elements in the stack as result

#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int> &ast)
{
    int n = ast.size();
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            st.push(ast[i]);
        }
        else if (ast[i] > 0)
        {
            st.push(ast[i]);
        }
        else // ast[i] < 0
        {
            while (!st.empty() && st.top() > 0 && abs(ast[i]) > st.top())
            {
                st.pop();
            }

            if (st.empty())
            {
                st.push(ast[i]);
            }
            else if (st.top() > 0 && abs(ast[i]) == st.top())
            {
                st.pop(); // both destroy
            }
            else if (st.top() < 0)
            {
                st.push(ast[i]); // same direction do nothing
            }
            // else: current asteroid destroyed
        }
    }

    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
