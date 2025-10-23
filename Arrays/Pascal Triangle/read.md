// -------------------------------------- Case 1 --------------------------------------
// 🔹 If anyone wants to know the element at a specific (row, col):

// ➤ For 1-based indexing:
//     Element = (r - 1) C (c - 1)

// ➤ For 0-based indexing:
//     Element = (r) C (c)

// 🧠 Example of Pascal’s Triangle (0-indexed):
// Row 0:          1
// Row 1:         1 1
// Row 2:        1 2 1
// Row 3:       1 3 3 1
// Row 4:      1 4 6 4 1

// Example:
// If we want the element at (r = 3, c = 1):
// → Using 0-based indexing → 3C1 = 3
// → Using 1-based indexing → (3 - 1)C(1 - 1) = 2C0 = 1


// -------------------------------------- Case 2 --------------------------------------
// 🔹 If anyone wants to print all elements of a given row:

// ➤ For 0-based indexing:
// Step 1: Initialize ans = 1
// Step 2: Push ans to result (first element is always 1)
// Step 3: Loop i = 1 to row
//         ans = ans * (row - i + 1) / i
//         push ans to result

// Example: row = 3
// Pascal row → [1, 3, 3, 1]
// Step-by-step:
// ans = 1 → push → [1]
// i = 1 → ans = 1 * (3 - 1 + 1) / 1 = 3 → push → [1, 3]
// i = 2 → ans = 3 * (3 - 2 + 1) / 2 = 3 → push → [1, 3, 3]
// i = 3 → ans = 3 * (3 - 3 + 1) / 3 = 1 → push → [1, 3, 3, 1]

// ➤ For 1-based indexing (just remove the +1 in the formula):
// Step 1: Initialize ans = 1
// Step 2: Push ans to result (first element is always 1)
// Step 3: Loop i = 1 to row
//         ans = ans * (row - i) / i
//         push ans to result

// Example: row = 3
// Pascal row → [1, 3, 3, 1]
// Step-by-step:
// ans = 1 → push → [1]
// i = 1 → ans = 1 * (3 - 1) / 1 = 2 → push → [1, 2]
// i = 2 → ans = 2 * (3 - 2) / 2 = 1 → push → [1, 2, 1]
// i = 3 → ans = 1 * (3 - 3) / 3 = 0 → push → [1, 2, 1, 0] (here 1-based indexing usually adjusts row definition)
