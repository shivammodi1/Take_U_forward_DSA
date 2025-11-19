# Linked List — How It Works (Diagram Explanation)

A **Linked List** is a linear data structure where each element (node) stores:

- **data**
- **pointer** to the **next** node

---

## 📌 Node Structure

```c
struct Node {
    int data;
    Node* next;
};
```

---

# 📦 Structure of a Node (Diagram)

### **32-bit System (each pointer = 4 bytes)**

```
+------------+------------+
|   data     |   next     |
|  (4 bytes) |  (4 bytes) |
+------------+------------+
       8 bytes per node
```

### **64-bit System (each pointer = 8 bytes)**  
(includes 4-byte padding for alignment)

```
+------------+----------------+------------+
|   data     |     next       |  padding   |
|  (4 bytes) |   (8 bytes)    |  (4 bytes) |
+------------+----------------+------------+
               16 bytes per node
```

---

# 📘 Example Linked List

Let's build the list:

```
10 → 20 → 30 → NULL
```

---

# 📚 Step-by-Step Diagram

## **Step 1: Create Node (10)**

```
+---------+-----------+
|  data   |   next    |
+---------+-----------+
|   10    |   NULL    |
+---------+-----------+
```

---

## **Step 2: Create Node (20) and Link**

```
 Node1 (10)                   Node2 (20)
+---------+-----------+     +---------+-----------+
|  data   |   next    | --> |  data   |   next    |
+---------+-----------+     +---------+-----------+
|   10    |   addr2   |     |   20    |   NULL    |
+---------+-----------+     +---------+-----------+
```

---

## **Step 3: Create Node (30) and Link**

```
 Node1 (10)                   Node2 (20)                   Node3 (30)
+---------+-----------+     +---------+-----------+     +---------+-----------+
|  data   |   next    | --> |  data   |   next    | --> |  data   |   next    |
+---------+-----------+     +---------+-----------+     +---------+-----------+
|   10    |   addr2   |     |   20    |   addr3   |     |   30    |   NULL    |
+---------+-----------+     +---------+-----------+     +---------+-----------+
```

---

# 🏁 Final Linked List Representation

```
HEAD
 |
 v
+---------+-----------+     +---------+-----------+     +---------+-----------+
|   10    |   •••─────┼───> |   20    |   •••─────┼───> |   30    |   NULL    |
+---------+-----------+     +---------+-----------+     +---------+-----------+
```

Simplified:

```
HEAD → [10|•] → [20|•] → [30|NULL]
```

---

# 🔍 Optional Detailed Memory View (32-bit Example)

```
Address:   Node
0x1000 →  [10 | 0x2000]
0x2000 →  [20 | 0x3000]
0x3000 →  [30 | NULL]
```

# 🧠 Simple Difference in One Line
Node → actual node (complete structure)

Node* → address of a node (pointer)

Node a;      // actual node
Node* p;     // pointer to a node


a:


+---------+-----------+
| data    | next      |
+---------+-----------+

p:


+-----------------+
| address of a    |
+-----------------+
