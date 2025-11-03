#include <bits/stdc++.h>
using namespace std;

vector<long long> sumOfThree(long long num)
{
    // num % 3 == 0 hoga toh hi solution hoga otherwise no solution
    // let x is first element
    // { x, x+1, x+2 }
    // 3x+3 => 3(x+1) = num

    if (num % 3 != 0)
    {
        return {};
    }

    long long x = num / 3 - 1;
    return {x, x + 1, x + 2};
}