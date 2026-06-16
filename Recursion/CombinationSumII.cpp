/*
Problem: Combination Sum II

Platform: LeetCode
Problem Link: https://leetcode.com/problems/combination-sum-ii/

Difficulty: Medium

Concepts Used:
- Backtracking
- Recursion
- Sorting
- Duplicate Handling

Problem Statement:
Given a collection of candidate numbers (candidates) and a target number (target),
find all unique combinations in candidates where the candidate numbers sum to target.

Rules:
1. Each number may be used at most once in each combination.
2. The solution set must not contain duplicate combinations.

Approach:
1. Sort the array.
   - Helps in handling duplicates efficiently.
   - Enables early stopping when a number exceeds the remaining target.

2. Use Backtracking:
   - Try including each candidate starting from the current index.
   - Reduce the target by the chosen number.
   - Move to the next index (i + 1) since each element can be used only once.

3. Skip Duplicates:
   - If the current element is the same as the previous element at the same recursion level,
     skip it to avoid generating duplicate combinations.
     
     if (i > index && candidates[i] == candidates[i - 1])
         continue;

4. Pruning:
   - Since the array is sorted, if candidates[i] > target,
     no further elements can contribute to a valid combination.
   - Break immediately.

Time Complexity:
O(2^n)
- In the worst case, every element can either be chosen or skipped.

Space Complexity:
O(n)
- Recursion stack depth.
- Excluding the space required for storing the answer.

Example 1:
Input:
candidates = [10,1,2,7,6,1,5]
target = 8

Output:
[
  [1,1,6],
  [1,2,5],
  [1,7],
  [2,6]
]

Explanation:
Unique combinations whose sum equals 8 are:
1 + 1 + 6 = 8
1 + 2 + 5 = 8
1 + 7 = 8
2 + 6 = 8

Example 2:
Input:
candidates = [2,5,2,1,2]
target = 5

Output:
[
  [1,2,2],
  [5]
]

Explanation:
Duplicate combinations are removed, leaving only unique answers.

Key Learning:
- Backtracking for generating combinations
- Sorting to simplify duplicate handling
- Skipping duplicates at the same recursion depth
- Early pruning to improve efficiency
*/

class Solution {
public:
    void solve(vector<int>& candidates,
               int target,
               int index,
               vector<int> cur,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(cur);
            return;
        }

        for (int i = index; i < candidates.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            // Since the array is sorted, no need to continue further
            if (candidates[i] > target)
                break;

            cur.push_back(candidates[i]);

            solve(candidates,
                  target - candidates[i],
                  i + 1,
                  cur,
                  ans);

            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, target, 0, curr, ans);

        return ans;
    }
};
