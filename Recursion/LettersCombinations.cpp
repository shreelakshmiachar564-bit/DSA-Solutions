/*
Problem: Letter Combinations of a Phone Number

Platform: LeetCode
Problem Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Difficulty: Medium

Concepts Used:
- Backtracking
- Recursion
- String Manipulation

Problem Statement:
Given a string containing digits from 2-9 inclusive, return all possible
letter combinations that the number could represent.

The mapping of digits to letters is the same as on a telephone keypad:

2 -> abc
3 -> def
4 -> ghi
5 -> jkl
6 -> mno
7 -> pqrs
8 -> tuv
9 -> wxyz

Return the answer in any order.

Example:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Approach:
1. Create a mapping of digits to their corresponding letters.
2. Use backtracking to generate all possible combinations.
3. For each digit, try every possible letter.
4. Once the current combination length equals the number of digits,
   add it to the answer.
5. Backtrack and explore other possibilities.

Time Complexity:
O(4^n * n)
- Each digit can contribute up to 4 letters.
- There are at most 4^n combinations.
- Creating each combination takes O(n).

Space Complexity:
O(n)
- Recursion stack depth is equal to the number of digits.
*/
class Solution {
public:
    vector<string> ans;
    void solve(vector<string> &digits,int index,string &cur,vector<string> &mp){
        if(index ==  digits.size()){
            ans.push_back(cur);
            return;
        }

        string letters = mp[digits[index]-'0'];
        for(char ch:letters){
            cur.push_back(ch);
            solve(digits,index+1,cur,mp);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"","",abc,def,ghi,jkl,mno,pqrs,tuv,wxyz};
        string cur = "";
        solve(digits,index,cur,mp);
        return ans;
    }
};
