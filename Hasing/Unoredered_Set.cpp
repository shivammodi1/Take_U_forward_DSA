#include <bits/stdc++.h>
using namespace std;

/*
📌 C++ set vs unordered_set

--------------------------------------------------
🔹 unordered_set (Hashing Based)

- Implemented using Hash Table
- Elements stored in random order (no sorting)

✅ Properties:
- Stores unique elements only
- Orderless
- Uses hashing internally

⏱ Time Complexity:
- Insertion → O(1) average
- Deletion → O(1) average
- Search → O(1) average
- Worst case → O(N) (collision)

🔧 Functions:

insert()
unordered_set<int> s;
s.insert(10);

count()
s.count(10); // 1 or 0

find()
if(s.find(10) != s.end()) cout<<"Found";

erase()
s.erase(10);

size()
s.size();

empty()
s.empty();

clear()
s.clear();

bucket_count()
s.bucket_count();

--------------------------------------------------
🔹 # set (Tree Based)

- Implemented using Red-Black Tree
- Elements stored in sorted order

✅ Properties:
- Stores unique elements
- Automatically sorted

⏱ Time Complexity:
- Insertion → O(log n)
- Deletion → O(log n)
- Search → O(log n)

🔧 Functions:

insert()
set<int> s;
s.insert(10);

find()
if(s.find(10) != s.end()) cout<<"Found";

erase()
s.erase(10);

size()
s.size();

empty()
s.empty();

clear()
s.clear();

lower_bound()
s.lower_bound(10);

upper_bound()
s.upper_bound(10);

*/

int main() {
    unordered_set<int> s;
    s.insert(10);
    s.insert(10);
    s.insert(50);
    s.insert(70);
    s.insert(60);

    for(auto it : s) {
        cout << it << " ";
    }
    cout << endl;
    // find element
    if(s.find(50) != s.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }

    // erase element
    s.erase(50);

    // check if element is erased
    if(s.find(50) != s.end()) {
        cout << "Found" << endl;
    } else {
        cout << "Not Found" << endl;
    }   

    // size of unordered_set
    cout << "Size: " << s.size() << endl;

    // check if unordered_set is empty
    if(s.empty()) {
        cout << "Empty" << endl;
    } else {
        cout << "Not Empty" << endl;
    }

    // clear unordered_set
    s.clear();
    

    return 0; 
}