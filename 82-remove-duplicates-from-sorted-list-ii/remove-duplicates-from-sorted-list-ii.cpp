class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* dummy = new ListNode(0); // Dummy node
        dummy->next = head;
        ListNode* prev = dummy; // Pointer to track unique elements

        while (head) {
            // Skip duplicates
            if (head->next && head->val == head->next->val) {
                int duplicateVal = head->val;
                while (head && head->val == duplicateVal)
                    head = head->next; // skip all duplicates
                prev->next = head; // unlink duplicates
            } else {
                prev = prev->next; // move prev normally
                head = head->next; // move head
            }
        }

        return dummy->next;
    }
};
