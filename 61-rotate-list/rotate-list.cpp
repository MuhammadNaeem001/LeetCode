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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head; // empty or single node
        
        // 1️⃣ Count list length
        int length = 1;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
            length++;
        }
        
        // 2️⃣ Make it circular
        tail->next = head;
        
        // 3️⃣ Find new tail position
        k = k % length;
        int stepsToNewTail = length - k;
        ListNode* newTail = head;
        for(int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }
        
        // 4️⃣ Set new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        
        return newHead;
    }
};
