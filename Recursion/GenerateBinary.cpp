/*
Problem: Generate Binary Strings Without Consecutive 1's

Platform: GeeksforGeeks / Recursion Practice

Difficulty: Medium

Concepts Used:
- Recursion
- Backtracking
- String Generation

Problem Statement:
Generate all binary strings of length N such that
no two consecutive '1's are present.

Rules:
- '0' can be placed at any position.
- '1' can be placed only if the previous character is not '1'.

Approach:
1. Start with an empty string.
2. At each step:
   - Always append '0'.
   - Append '1' only when the previous character is not '1'.
3. When the current string length becomes N,
   store it in the answer vector.
4. The total count is the size of the generated result vector.

Time Complexity:
O(2^N)
- In the worst case, all valid strings are generated.

Space Complexity:
O(2^N * N)
- Storing all valid strings.
- Recursion stack depth is O(N).

Example:
Input:
N = 3

Generated Strings:
000
001
010
100
101

Output:
5

Key Learning:
- Recursive string generation
- Backtracking with constraints
- Decision making based on previous state
*/

class Solution {
public:
    
    void solve(int n, string curr, vector<string>& ans) {
        
        // Base Case
        if (curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        // Always place '0'
        solve(n, curr + '0', ans);

        // Place '1' only if previous character is not '1'
        if (curr.empty() || curr.back() != '1') {
            solve(n, curr + '1', ans);
        }
    }

    int countStrings(int n) {
        vector<string> ans;

        solve(n, "", ans);

        return ans.size();
    }
};
