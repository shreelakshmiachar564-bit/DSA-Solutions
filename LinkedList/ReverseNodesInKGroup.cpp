/*
Problem: Reverse Nodes in K-Group

Platform: LeetCode
Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

Difficulty: Hard

Concepts Used:
- Linked List
- Pointer Manipulation
- Iterative Reversal

Problem Statement:
Given the head of a linked list, reverse the nodes of the list k at a time,
and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list.
If the number of nodes is not a multiple of k, then the remaining nodes at the end
should remain as they are.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

Approach:
1. Create a dummy node pointing to head.
2. Find the kth node from the current group.
3. If fewer than k nodes remain, stop.
4. Reverse the current group using pointer manipulation.
5. Reconnect the reversed group with the remaining list.
6. Move to the next group and repeat.

Time Complexity:
O(n)
- Each node is visited a constant number of times.

Space Complexity:
O(1)
- Reversal is done in-place without extra space.

Example:
Input:
head = [1,2,3,4,5], k = 2

Output:
[2,1,4,3,5]

Input:
head = [1,2,3,4,5], k = 3

Output:
[3,2,1,4,5]

Key Learning:
- In-place linked list reversal
- Group-wise pointer handling
- Dummy node usage for edge cases
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //first check for single pnt  or k=1
        if(head == nullptr||k==1) return head;


        //create the dummy node 
        ListNode  dummy(0);
        dummy.next = head;
        ListNode * grpPrev = &dummy;

        while(true){
             //run th loop to reach the end of the group
            ListNode *kth = grpPrev;

            for(int i=0;i<k&&kth!=nullptr;i++){
                kth=kth->next;
            }


            //if reach the end of  exit 
            if(kth == nullptr) break;

            //update the curr->start of  cur group , next-grp start  and prev->that will be curr next pointer 
            ListNode * grpNext = kth->next;
            ListNode * curr = grpPrev->next;
            ListNode * prev = grpNext;

            while(curr != grpNext){
                ListNode * temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }


            //update to reconnect the old wth new 
            ListNode * temp = grpPrev->next;
            grpPrev->next = kth;

            grpPrev = temp;
        }
        return dummy.next;
       
    }
};
