class Solution {
private:
    void partitionRecursive(ListNode* node, int x, ListNode*& lessTail, ListNode*& greaterTail){
        if(node == NULL){
            return;
        }
        if(node->val < x) {
            lessTail->next = node;  // Link the node to the 'less' list
            lessTail = lessTail->next; // Move the lessTail pointer
        }else{
            greaterTail->next = node; // Link the node to the 'greater' list
            greaterTail = greaterTail->next; // Move the greaterTail pointer
        }
        // Recurse on the next node
        partitionRecursive(node->next, x, lessTail, greaterTail);
    }
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessDummy = new ListNode(0);
        ListNode* greaterDummy = new ListNode(0);
        ListNode* lessTail = lessDummy;
        ListNode* greaterTail = greaterDummy;
        partitionRecursive(head, x, lessTail, greaterTail);
        greaterTail->next = NULL;
        // Connect less list with greater list
        lessTail->next = greaterDummy->next;
        // Store the start of the partitioned list
        ListNode* partitionedHead = lessDummy->next;
        delete lessDummy;
        delete greaterDummy;
        return partitionedHead;
    }
};
