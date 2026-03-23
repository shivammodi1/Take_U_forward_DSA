#include<bits/stdc++.h>
using namespace std;

/*
📌 C++ map + unordered_map (Complete Notes)

==================================================
🔹 unordered_map (Hashing Based)

- Implemented using Hash Table
- Stores (key, value) pairs
- Keys are unique
- Order is NOT maintained (random)

--------------------------------------------------
✅ Properties:
- Key → Value mapping
- Unique keys
- Fast lookup using hashing

--------------------------------------------------
⏱ Time Complexity:
- Insertion → O(1) average
- Deletion → O(1) average
- Search → O(1) average
- ❗ Worst case → O(N) (collision)

--------------------------------------------------
🔧 Functions:

insert()
unordered_map<int,int> mp;
mp.insert({1,100});

[] operator
mp[2] = 200;

👉 create/update both

access
cout << mp[1];

find()
if(mp.find(1) != mp.end()) cout<<"Found";

count()
mp.count(1); // 1 or 0

erase()
mp.erase(1);

size()
mp.size();

empty()
mp.empty();

clear()
mp.clear();

--------------------------------------------------
🔁 Traversal (Random Order)

for(auto it : mp){
    cout << it.first << " " << it.second << endl;
}

==================================================
🔹 map (Tree Based)

- Implemented using Red-Black Tree
- Stores (key, value) pairs
- Keys stored in sorted order

--------------------------------------------------
✅ Properties:
- Key → Value mapping
- Unique keys
- Automatically sorted

--------------------------------------------------
⏱ Time Complexity:
- Insertion → O(log n)
- Deletion → O(log n)
- Search → O(log n)

--------------------------------------------------
🔧 Functions:

insert()
map<int,int> mp;
mp.insert({1,100});

[] operator
mp[2] = 200;

access
cout << mp[1];

find()
if(mp.find(1) != mp.end()) cout<<"Found";

count()
mp.count(1);

erase()
mp.erase(1);

size()
mp.size();

empty()
mp.empty();

clear()
mp.clear();

--------------------------------------------------
🔁 Traversal (Sorted Order)

for(auto it : mp){
    cout << it.first << " " << it.second << endl;
}

==================================================
🔥 Key Differences

map vs unordered_map:

- Order: sorted vs not sorted
- DS: Red-Black Tree vs Hash Table
- Time: O(log n) vs O(1) avg
- Worst: O(log n) vs O(N)

==================================================
💡 When to Use

- Use map → when sorted keys needed
- Use unordered_map → for fast lookup

==================================================
🧠 Interview Tips

- unordered_map fastest (avg)
- map gives sorted output
- [] operator inserts automatically
- collisions → unordered_map worst case O(N)
*/

int main(){

    unordered_map<int,int> mp;
    // 1 -> 100 where 1 is key and 100 is value
    mp.insert({1,100});
    mp[2] = 200;
    cout << mp[1] << endl;

    // Check if key exists
     if(mp.find(1) != mp.end()) cout<<"Found" << endl;

     mp.erase(1); // Remove key 1

     // Traversal (Random Order)
     for(auto it : mp){
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}





