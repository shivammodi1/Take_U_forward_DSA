# Array 
- An array is a data structure that can hold a fixed number of values of a single type.
- The max size of an Array we can create inside the int main is 10^6.
- The max size of an Array we can create globally is 10^7.
- When we create an Array inside the int main, the value inside the Array is garbage value.
- When we create an Array globally, the value inside the Array is 0.
example:
```cpp
#include <bits/stdc++.h>
using namespace std;
int arr[10000000]; // Global array, initialized to 0
int main() {
    int arr2[1000000]; // Local array, contains garbage values
    cout << arr[0] << endl; // Output: 0
    cout << arr2[0] << endl; // Output: garbage value
    return 0;
}
```
- We can initialize an array at the time of declaration.
example:
```cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[5] = {1, 2, 3, 4, 5}; // Array initialization
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " "; // Output: 1 2 3 4 5
    }
    return 0;
}
```

- Element stored in contiguous memory locations.
- We can access the elements of an array using the index.