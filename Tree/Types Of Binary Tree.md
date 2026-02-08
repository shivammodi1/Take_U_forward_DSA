# Types Of Binary Tree
1. **Full Binary Tree**: A binary tree in which every node has either *0 or 2 children.* 
- Example:
```
        1
       / \
      2   3
     / \
    4   5
```

2. **Complete Binary Tree**: A binary tree in which *all levels are completely filled except the last level,* and the last level has all keys as left as possible.
- Example:
```
        1                   1
       / \                 /  \
      2   3               2    3 
     / \                 / \  / \
    4   5               4  5  6  7
```

3. **Perfect Binary Tree**: A binary tree in which *all internal nodes have two children and all leaves are at the same level.*
- Example:
```
        1
       / \
      2   3
     / \ / \
    4  5 6  7
```

4. **Balanced Binary Tree**: A binary tree in which the difference in *height between the left and right subtrees of any node is no more than one.*
- Example:
```            
        1         height Of left subtree = 2
       / \        height Of right subtree = 1
      2   3       balanced treee = 2-1 = 1 -> less than or equal to 1
     / 
    4   
```

5. **Degenerate (or Pathological) Tree**: A binary tree *where each parent node has only one child. This can be thought of as a linked list.*
- Example:
```
        1
         \
          2
           \
            3
             \
              4
```


