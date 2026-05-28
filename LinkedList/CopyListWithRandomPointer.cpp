/*
Problem: Copy List with Random Pointer

Platform: LeetCode
Problem Link: https://leetcode.com/problems/copy-list-with-random-pointer/

Difficulty: Medium

Concepts Used:
- Linked List
- Hash Map
- Pointer Manipulation
- Deep Copy

Problem Statement:
A linked list is given where each node contains:
1. next pointer -> points to the next node
2. random pointer -> points to any node in the list or NULL

Create a deep copy of the list such that:
- Each new node has the same value as the original node.
- next and random pointers of the new nodes should point to copied nodes.
- None of the pointers in the new list should point to original nodes.

Approach:
1. Traverse the original list and create a copy node for each node.
2. Store mapping between original nodes and copied nodes using a hash map.
3. Traverse again to connect:
   - next pointers
   - random pointers
4. Return the head of the copied list.

Alternative Optimized Approach:
1. Insert copied nodes between original nodes.
2. Assign random pointers using adjacent copied nodes.
3. Separate the original and copied lists.

Time Complexity:
O(n)
- Each node is visited a constant number of times.

Space Complexity:
O(n)
- Hash map is used to store node mappings.

Example:
Input:
head = [[7,null],[13,0],[11,4],[10,2],[1,0]]

Output:
[[7,null],[13,0],[11,4],[10,2],[1,0]]

Key Learning:
- Deep copying linked lists
- Handling random pointers
- Hash map usage with pointers
- Optimized in-place node cloning
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // base condition
        if (head == nullptr)
            return head;

        // first copy all the nodes next to the original nodes;
        Node* cur = head;
        while (cur != nullptr) {
            Node* copy = new Node(cur->val);
            Node* nextOriginal = cur->next;

            cur->next = copy;
            copy->next = nextOriginal;

            cur = nextOriginal;
        }

        // copy all the randompointer of original node;

        cur = head;
        while (cur != nullptr) {
            if (cur->random != nullptr) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }

        // sepearte oroginal and copy Node;

        cur = head;
        Node* dummy = new Node(0);
        Node* copyCur = dummy;

        while (cur != nullptr) {
            Node* copy = cur->next;
            Node* nextOrg = copy->next;

            copyCur->next = copy;
            copyCur = copyCur->next;

            cur->next = nextOrg;
            cur = cur->next;
        }
        return dummy->next;
    }
};
