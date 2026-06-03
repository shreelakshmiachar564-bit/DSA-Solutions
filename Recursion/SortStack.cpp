/*
Problem: Sort a Stack Using Recursion

Platform: Coding Interview / Recursion Problem

Difficulty: Medium

Concepts Used:
- Recursion
- Stack
- Backtracking

Problem Statement:
Given a stack of integers, sort the stack in ascending order
using recursion only.

Constraints:
- No loops
- No extra data structures
- Only recursive calls are allowed

Approach:
1. Remove the top element from the stack.
2. Recursively sort the remaining stack.
3. Insert the removed element into its correct position
   in the sorted stack using another recursive function.

Recursive Functions:
1. sortStack()
   - Sorts the stack recursively.

2. insertSorted()
   - Inserts an element into its correct position
     in an already sorted stack.

Time Complexity:
O(n²)

Explanation:
For each element, we may traverse the entire stack again
during insertion.

Space Complexity:
O(n)

Explanation:
Recursion call stack.

Example:

Input Stack (Top -> Bottom):
3
1
4
2

Sorted Stack (Top -> Bottom):
4
3
2
1

Key Learning:
- Solving stack problems using recursion
- Recursive insertion
- Backtracking technique
*/
class Solution {
  public:
  void insertSorted(stack<int> &st,int ele){
      if(st.empty()||st.top()<=ele){
          st.push(ele);
          return;
      }
      
      int topEle = st.top();
      st.pop();
      
      insertSorted(st,ele);
      
      st.push(topEle);
  }
    void sortStack(stack<int> &st) {
        // code here
        if(st.empty())return;
        
        int topEle = st.top();
        st.pop();
        
        sortStack(st);
        
        insertSorted(st,topEle);
    }
};
