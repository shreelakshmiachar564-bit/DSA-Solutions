/*
Problem: String to Integer (atoi)

Platform: LeetCode
Problem Link: https://leetcode.com/problems/string-to-integer-atoi/

Difficulty: Medium

Concepts Used:
- Strings
- Recursion
- Parsing
- Overflow Handling

Problem Statement:
Implement the myAtoi(string s) function, which converts a string
to a 32-bit signed integer.

Rules:
1. Ignore leading whitespace characters.
2. Check for an optional '+' or '-' sign.
3. Read digits until a non-digit character is encountered.
4. If no digits are found, return 0.
5. Clamp the result within the 32-bit signed integer range:
   INT_MAX = 2147483647
   INT_MIN = -2147483648

Approach:
1. Skip leading whitespaces.
2. Determine the sign (+ or -).
3. Use recursion to process digits one by one.
4. Build the number using:
      num = num * 10 + digit
5. Before adding a digit, check for overflow:
      num > (INT_MAX - digit) / 10
6. Return the signed result.

Time Complexity:
O(n)
- Each character is processed at most once.

Space Complexity:
O(n)
- Recursive call stack can grow up to n.

Example 1:
Input:
s = "42"

Output:
42

Example 2:
Input:
s = "   -42"

Output:
-42

Example 3:
Input:
s = "4193 with words"

Output:
4193

Example 4:
Input:
s = "words and 987"

Output:
0

Example 5:
Input:
s = "-91283472332"

Output:
-2147483648

Key Learning:
- Recursive string processing
- Handling optional signs
- Overflow detection
- Safe integer conversion
*/

class Solution {
public:
    long long myRec(const string& s, int i, long long num, int sign) {

        // Stop when end of string or non-digit is reached
        if (i >= s.length() || !isdigit(static_cast<unsigned char>(s[i]))) {
            return num * sign;
        }

        int digit = s[i] - '0';

        // Overflow check
        if (num > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        return myRec(s, i + 1, num * 10 + digit, sign);
    }

    int myAtoi(string s) {
        int i = 0;

        // Skip leading whitespaces
        while (i < s.length() && s[i] == ' ') {
            i++;
        }

        // Determine sign
        int sign = 1;
        if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        return static_cast<int>(myRec(s, i, 0, sign));
    }
};
