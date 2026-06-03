/*
Problem: Reverse a Stack Using Recursion

Platform: Coding Interview / Recursion Problem

Difficulty: Medium

Concepts Used:
- Recursion
- Stack
- Backtracking

Problem Statement:
Given a stack, reverse its contents using recursion only.

Constraints:
- No loops
- No extra data structures
- Only recursive calls are allowed

Approach:
1. Remove the top element.
2. Recursively reverse the remaining stack.
3. Insert the removed element at the bottom of the stack.

Recursive Functions:
1. reverseStack()
   - Reverses the stack recursively.

2. insertAtBottom()
   - Inserts an element at the bottom of the stack.

Time Complexity:
O(n²)

Explanation:
For every element, we may traverse the entire stack again
while inserting at the bottom.

Space Complexity:
O(n)

Explanation:
Recursive call stack.

Example:

Input Stack (Top -> Bottom):
4
3
2
1

Output Stack (Top -> Bottom):
1
2
3
4

Key Learning:
- Recursion with stacks
- Backtracking
- Insert-at-bottom technique
*/
class Solution {
  public:
    void insertAtBottom(stack<int> &st,int ele){
        if(st.empty()){
            st.push(ele);
            return;
        }
        
        int topEle = st.top();
        st.pop();
        
        insertAtBottom(st,ele);
        st.push(topEle);
    }
    void reverseStack(stack<int> &st) {
        // code here
        if(st.empty()) return;
        
        int topEle = st.top();
        st.pop();
        
        reverseStack(st);
        
        insertAtBottom(st,topEle);
    }
};
