# What is the Two Pointers Pattern?
- The Two Pointers involves using two indices to iterate over the data structure, to solve problem efficiently by avoiding nested loops.

# When to use the Two Pointers Pattern?
- When you need to find pairs in a sorted array.
- When you need to find triplets in a sorted array.
- When the data structure is sorted and you need to find a specific condition (e.g., sum, difference, etc.).
`- When you need to reverse a string or an array in place.
- When you need to partition an array based on a condition 
(e.g., even/odd)
- When you need to find the longest substring without repeating characters.

# Typically Approach:
1. Initialze two ponters, left and right.
2. Check condition based on the current pointers.
3. Move the pointers based on the condition.
    i. If the condition is met, move the left pointer to the right.
    ii. If the condition is not met, move the right pointer to the left.
4. Repeat until the pointers meet or cross each other.