class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Base case: if the current node is null, return null
        if(head == NULL){
            return NULL;
        }
        // Recursive call to process the rest of the list
        head->next = removeElements(head->next, val);
        // Determine if the current node should be removed
        if(head->val == val){
            ListNode* nextNode = head->next;
            delete head; // Free memory 
            return nextNode;
        }else{
            return head;
        }
    }
};
