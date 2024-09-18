class Solution {
private:
    int getDecimalValueRecursive(ListNode* node, int power) {
        if(node == NULL) return 0;
        // Calculate the value of the current node and add it to the result of the rest of the list
        return (node->val << power) + getDecimalValueRecursive(node->next, power - 1);
    }
public:
    int getDecimalValue(ListNode* head){
        int length = 0;
        ListNode* current = head;
        // Calculate the length of the linked list
        while(current != NULL){
            length++;
            current = current->next;
        }
        // Call the recursive function
        return getDecimalValueRecursive(head, length - 1);
    }
};
