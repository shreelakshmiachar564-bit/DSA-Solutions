/*
Problem: Power Set (All Subsequences)

Platform: Recursion / Backtracking

Difficulty: Easy

Concepts Used:
- Recursion
- Backtracking
- Include / Exclude Pattern

Problem Statement:
Given a string, generate all possible subsequences
(the power set) of the string.

A subsequence can be formed by deleting zero or more
characters without changing the order of the remaining characters.

Approach:
For every character, we have two choices:
1. Include the character.
2. Exclude the character.

Recursively explore both possibilities.

Time Complexity:
O(2^n)

Explanation:
Each character has 2 choices.

Space Complexity:
O(n)

Explanation:
Recursion stack depth.

Example:
Input:
"abc"

Output:
"abc"
"ab"
"ac"
"a"
"bc"
"b"
"c"
""

Key Learning:
- Include/Exclude Recursion Pattern
- Foundation for Backtracking Problems
*/
class Solution {
  public:
    void solve(string s, int i,string cur,vector<string> &ans){
        if(i == s.length()){
            ans.push_back(cur);
            return;
        }
        
        //including the current  char
        solve(s,i+1, cur+s[i],ans);
        
        //excluding the crrent character
        solve(s,i+1,cur,ans);
    }
    vector<string> powerSet(string &s) {
        // Code here
        vector<string> ans;
        
        solve(s,0,"",ans);
        
        //to get the lexicographically sorted order
        sort(ans.begin(),ans.end());
        return ans;
    }
};
