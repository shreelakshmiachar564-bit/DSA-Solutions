/*
Problem: Pow(x, n)

Platform: LeetCode
Problem Link: https://leetcode.com/problems/powx-n/

Difficulty: Medium

Concepts Used:
- Recursion
- Divide and Conquer
- Binary Exponentiation
- Fast Power

Problem Statement:
Implement pow(x, n), which calculates x raised to the power n (xⁿ).

Requirements:
- Handle positive and negative exponents.
- Return the result as a double.
- Optimize for large values of n.

Approach:
1. Use Binary Exponentiation (Exponentiation by Squaring).
2. Recursively calculate x^(n/2).
3. If n is even:
      xⁿ = (x^(n/2))²
4. If n is odd:
      xⁿ = (x^(n/2))² * x
5. For negative powers:
      x⁻ⁿ = (1/x)ⁿ
6. Convert n to long long to safely handle INT_MIN.

Time Complexity:
O(log n)
- Exponent is divided by 2 in every recursive call.

Space Complexity:
O(log n)
- Recursive call stack.

Example 1:
Input:
x = 2.00000, n = 10

Output:
1024.00000

Example 2:
Input:
x = 2.10000, n = 3

Output:
9.26100

Example 3:
Input:
x = 2.00000, n = -2

Output:
0.25000

Explanation:
2⁻² = 1 / (2²)
     = 1 / 4
     = 0.25

Key Learning:
- Binary Exponentiation
- Divide and Conquer
- Handling negative exponents
- Avoiding overflow using long long
*/

class Solution {
public:
    double power(double x, long long n) {
        // Base Case
        if (n == 0)
            return 1.0;

        double half = power(x, n / 2);

        // Even Power
        if (n % 2 == 0)
            return half * half;

        // Odd Power
        return half * half * x;
    }

    double myPow(double x, int n) {
        long long N = n;

        // Handle negative exponent
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        return power(x, N);
    }
};
