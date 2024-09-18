class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int result = 0;
        while (head != NULL) {
            result = result * 2 + head->val;  // Shift left and add current node's value
            head = head->next;  // Move to the next node
        }
        return result;
    }
};
