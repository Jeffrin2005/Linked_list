class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Base case: If the list is empty or has only one node, return it as is
        if (head == NULL || head->next == NULL ){
            return head;
        }
        // If current node is a duplicate
        if(head->val == head->next->val) {
            // Skip all nodes with the current duplicate value
            while(head->next != NULL  && head->val == head->next->val){
                head = head->next;
            }
            // Recursive call on the next distinct element
            return deleteDuplicates(head->next);
        }else{
            // If current node is unique, link it to the result of the recursive call on the next node
            head->next = deleteDuplicates(head->next);
            return head;
        }
    }
};
