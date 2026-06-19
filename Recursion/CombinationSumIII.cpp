/*
Problem: Combination Sum III

Platform: LeetCode
Problem Link: https://leetcode.com/problems/combination-sum-iii/

Difficulty: Medium

Concepts Used:
- Backtracking
- Recursion
- Combinatorics
- Depth First Search (DFS)

Problem Statement:
Find all valid combinations of k numbers that sum up to n such that:

1. Only numbers from 1 to 9 are used.
2. Each number can be used at most once.
3. The combination should contain exactly k numbers.
4. Return all possible valid combinations.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]

Explanation:
1 + 2 + 4 = 7 and the combination contains exactly 3 numbers.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]

Approach:
1. Use backtracking to generate combinations.
2. Start choosing numbers from 1 to 9.
3. Add a number to the current combination.
4. Reduce the target by that number.
5. Move to the next number since each number can be used only once.
6. If the target becomes 0 and the combination size equals k,
   store the combination.
7. Backtrack and explore other possibilities.

Time Complexity:
O(C(9, k))
- We generate combinations of numbers from 1 to 9.
- In the worst case, all valid combinations are explored.

Space Complexity:
O(k)
- Recursion stack depth and current combination size.
*/
