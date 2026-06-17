/*
Problem: 90. Subsets II

Platform: LeetCode
Problem Link: https://leetcode.com/problems/subsets-ii/

Difficulty: Medium

Concepts Used:
- Backtracking
- Recursion
- Sorting
- Duplicate Handling

Problem Statement:
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets.
Return the subsets in any order.

Example 1:
Input:
nums = [1,2,2]

Output:
[
    [],
    [1],
    [2],
    [1,2],
    [2,2],
    [1,2,2]
]

Example 2:
Input:
nums = [0]

Output:
[
    [],
    [0]
]

Algorithm:
1. Sort the input array.
   - Sorting places duplicate elements adjacent to each other.
   - This makes it easy to identify and skip duplicates.

2. Use backtracking to generate all subsets.
   - At each recursive call, add the current subset to the answer.
   - Iterate through the remaining elements starting from the current index.

3. Skip duplicate elements at the same recursion level:
   if(i > index && nums[i] == nums[i - 1])
       continue;

   This prevents generating identical subsets multiple times.

4. Include the current element:
   - Add it to the current subset.
   - Recurse for the next index.

5. Backtrack:
   - Remove the last element before exploring the next choice.

Why Sorting is Necessary:
Consider:
nums = [1,2,2]

After sorting:
[1,2,2]

At the same recursion level:
- First 2 is considered.
- Second 2 is skipped.

This prevents duplicate subsets such as:
[2]
[2]

while still allowing:
[2,2]

Time Complexity:
- Sorting: O(n log n)
- Generating subsets: O(2^n)
- Copying subsets into answer: O(n * 2^n)

Overall: O(n * 2^n)

Space Complexity:
- Recursion Stack: O(n)
- Excluding output storage

Solution:
*/

class Solution {
public:
    void solve(vector<int>& nums,
               int index,
               vector<int>& current,
               vector<vector<int>>& ans) {

        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > index && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);

            solve(nums, i + 1, current, ans);

            current.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> current;

        solve(nums, 0, current, ans);

        return ans;
    }
};
