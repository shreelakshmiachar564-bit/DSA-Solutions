/*
Problem: Generate Parentheses

Platform: LeetCode
Problem Link: https://leetcode.com/problems/generate-parentheses/

Difficulty: Medium

Concepts Used:
- Recursion
- Backtracking
- Combinatorics

Problem Statement:
Given n pairs of parentheses, generate all combinations
of well-formed parentheses.

A combination is valid if:
1. Every opening bracket '(' has a matching closing bracket ')'.
2. At no point should closing brackets exceed opening brackets.

Approach:
1. Keep track of:
   - openCount  -> number of '(' used
   - closeCount -> number of ')' used

2. Add '(' if openCount < n.

3. Add ')' only if:
      closeCount < openCount

4. When the current string length becomes 2 * n,
   add it to the answer.

Time Complexity:
O(4^n / √n)

Explanation:
- Number of valid combinations is the nth Catalan Number.

Space Complexity:
O(n)
- Recursion stack depth.

Example 1:
Input:
n = 3

Output:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

Example 2:
Input:
n = 1

Output:
[
  "()"
]

Key Learning:
- Backtracking with constraints
- Valid parentheses generation
- Catalan Number problems
*/

 void solve(int n, string curr,vector<string> &ans){
      if(curr.length()==n){
          ans.push_back(curr);
          return;
      }
      solve(n,curr+'0',ans);
      
      if(curr.empty()||curr.back()!='1'){
          solve(n,curr+'1',ans);
      }
  }
  int countStrings(int n) {
      // code here
      vector<string> ans;
      solve(n,"",ans);
      return ans.size();
  }
