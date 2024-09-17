class Solution {
public:
    ListNode* reverseList(ListNode* head) {
           ListNode* prev = NULL; // Previous node starts as nullptr
        ListNode* curr = head;    // Current node starts at the head
        ListNode* next = NULL; // Next node 
        while(curr != NULL){
            next = curr->next;  // Store next node
            curr->next = prev;  // Reverse current node's pointer
            prev = curr;        // Move prev and curr one step forward
            curr = next;
        }
        return prev; // prev will be the new head of the reversed list
    }
};
