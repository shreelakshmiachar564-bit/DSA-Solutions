/*
Problem: Flattening a Linked List

Platform: GeeksforGeeks
Problem Link: https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

Difficulty: Medium

Concepts Used:
- Linked List
- Recursion
- Merge Two Sorted Lists
- Divide and Conquer

Problem Statement:
Given a linked list where every node has two pointers:
1. next -> points to the next node in the main list
2. bottom -> points to a sorted linked list

Flatten the linked list into a single sorted linked list using the bottom pointer.

Approach:
1. Recursively flatten the linked list on the right side.
2. Merge the current list with the already flattened list.
3. Use a merge function similar to merging two sorted linked lists.
4. Maintain sorting while connecting nodes using the bottom pointer.
5. Set next pointers to NULL after merging.

Time Complexity:
O(N * M) approximately
- Each node is processed during merge operations.

Space Complexity:
O(1) auxiliary space
- Ignoring recursive call stack.

Example:
Input:
5 -> 10 -> 19 -> 28
|     |      |      |
7     20     22     35
|            |      |
8            50     40
|                   |
30                  45

Output:
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50

Key Learning:
- Recursive linked list flattening
- Merging sorted linked lists
- Efficient pointer manipulation
- Divide and conquer technique
*/

class Solution {
  public:
    Node * merge(Node *a, Node *b){
        if(a == nullptr) return b;
        if(b == nullptr) return a;
        
        Node * result;
        if(a->data<=b->data){
            result = a;
            result->bottom = merge(a->bottom,b);
        }
        else if(b->data<a->data){
            result = b;
            result->bottom = merge(a,b->bottom);
        }
        result ->next = nullptr;
        return result;
    }
    Node *flatten(Node *root) {
        // code here
        
        //base condition
        if(root == nullptr || root->next == nullptr) return root;
        
        root->next = flatten(root->next);
        merge(root,root->next);
        
        return root;
    }
};
