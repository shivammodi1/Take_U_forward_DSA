# Recursion 
- It is a technique in programming where a function calls itself to solve a problem. Until a base condition is met.
- It is commonly used for problems that can be broken down into smaller, similar subproblems.

## Example of a Recursive Function
Here is an example of a simple recursive function that calculates the factorial of a number:

```cpp
#include <iostream>
using namespace std;
int factorial(int n) {
    // Base case
    if (n == 0) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}
int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}
```

In this example, the `factorial` function calls itself with a decremented value of `n` until it reaches the base case where `n` is 0. At that point, it returns 1, and the recursive calls start to resolve, ultimately calculating the factorial of the original number.
## Tree Representation of Recursion
Consider calculating the factorial of 4 (i.e., `factorial(4)`):

```factorial(4)
    |
    +-- 4 * factorial(3)
            |
            +-- 3 * factorial(2)
                    |
                    +-- 2 * factorial(1)
                            |
                            +-- 1 * factorial(0)
                                    |
                                    +-- 1 (base case)
```