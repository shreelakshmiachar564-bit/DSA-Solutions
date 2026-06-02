/*
Problem: Count Good Numbers

Platform: LeetCode
Problem Link: https://leetcode.com/problems/count-good-numbers/

Difficulty: Medium

Concepts Used:
- Mathematics
- Recursion
- Binary Exponentiation (Fast Power)
- Modular Arithmetic

Problem Statement:
A digit string is called "good" if:

1. Digits at even indices (0, 2, 4, ...) are even:
   {0, 2, 4, 6, 8}
   => 5 choices

2. Digits at odd indices (1, 3, 5, ...) are prime:
   {2, 3, 5, 7}
   => 4 choices

Given an integer n, return the total number of good digit strings
of length n modulo (10^9 + 7).

Approach:
1. Count the number of even-indexed positions:
      evenPositions = (n + 1) / 2

2. Count the number of odd-indexed positions:
      oddPositions = n / 2

3. Calculate:
      5^(evenPositions) * 4^(oddPositions)

4. Use Binary Exponentiation to efficiently compute powers under modulo.

Time Complexity:
O(log n)
- Fast exponentiation divides the exponent by 2 at every step.

Space Complexity:
O(log n)
- Recursive call stack.

Example 1:
Input:
n = 1

Output:
5

Explanation:
Only index 0 exists and it must contain an even digit.
Possible strings:
"0", "2", "4", "6", "8"

Example 2:
Input:
n = 4

Output:
400

Explanation:
Even positions = 2
Odd positions = 2

Total:
5² × 4²
= 25 × 16
= 400

Key Learning:
- Counting possibilities using multiplication principle
- Binary Exponentiation
- Modular Arithmetic
- Handling very large exponents efficiently
*/

class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    long long power(long long x, long long n) {
        // Base Case
        if (n == 0)
            return 1;

        long long half = power(x, n / 2);

        long long ans = (half * half) % MOD;

        // If exponent is odd
        if (n % 2) {
            ans = (ans * x) % MOD;
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long evenPositions = (n + 1) / 2;
        long long oddPositions = n / 2;

        long long evenWays = power(5, evenPositions);
        long long oddWays = power(4, oddPositions);

        return static_cast<int>((evenWays * oddWays) % MOD);
    }
};
