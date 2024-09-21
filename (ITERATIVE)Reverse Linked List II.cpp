

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head==NULL || left == right) return head;
        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy;
        // Move prev to the node just before the left position
        for (int i = 0; i < left - 1; i++){
            prev = prev->next;
        }
        // Start pointer will point to the first node in the sublist to be reversed
        ListNode* start = prev->next;
        ListNode* then = start->next;

        // Perform the reversal between left and right
        for (int i = 0; i < right - left; i++){
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dynamically allocated dummy node
        return newHead;
    }
};
