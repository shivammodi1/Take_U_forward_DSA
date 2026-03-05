# Morris Traversal (Inorder Traversal without Stack or Recursion)

## Introduction
Morris Traversal ek Binary Tree traversal technique hai jisme hum Inorder Traversal (Left → Root → Right) ko O(1) extra space me perform karte hain.

Is technique me stack ya recursion use nahi hota. 
Iske instead hum tree ke nodes ke beech temporary links (threads) 
banate hain aur traversal complete hone ke baad un links ko remove kar dete hain.

---

## Intuition

Normal inorder traversal me do approaches hoti hain:

1. Recursion
2. Stack

Dono approaches me O(h) extra space lagta hai (h = tree height).

Morris Traversal me hum inorder predecessor ka use karke temporary link create karte hain taaki left subtree traverse karne ke baad wapas current node par aa sake.

Isse extra memory ki zarurat nahi padti.

---

## Key Concept: Inorder Predecessor

Inorder predecessor ka matlab hai:

Left subtree ka rightmost node.

Example tree:

      4
     /
    2
     \
      3

Yaha 4 ka inorder predecessor = 3 hai.

---

## Algorithm

1. current = root

2. Jab tak current NULL nahi hai:

### Case 1: Agar Left Child nahi hai

Agar current->left == NULL

- current node print karo
- right subtree me move karo

print(current->data)  
current = current->right

---

### Case 2: Agar Left Child exist karta hai

Agar current ka left child hai:

1. current ka inorder predecessor find karo (left subtree ka rightmost node)

2. Agar predecessor->right == NULL

- temporary link create karo
- predecessor->right = current
- left subtree me move karo

predecessor->right = current  
current = current->left

---

3. Agar predecessor->right == current

Matlab left subtree traverse ho chuka hai

- temporary link remove karo
- current node print karo
- right subtree me move karo

predecessor->right = NULL  
print(current->data)  
current = current->right

---

## Example

Binary Tree:

      4
     / \
    2   5
   / \
  1   3

Inorder Traversal Output:

1 2 3 4 5

Morris Traversal temporary link banata hai:

3 → 4

Traversal complete hone ke baad link remove ho jata hai aur tree original form me wapas aa jata hai.

---

## Complexity

Time Complexity: O(n)  
Har node maximum 2 baar visit hota hai.

Space Complexity: O(1)  
Koi extra stack ya recursion use nahi hota.

