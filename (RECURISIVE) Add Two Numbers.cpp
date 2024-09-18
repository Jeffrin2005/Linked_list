class Solution {
private:
    ListNode* addTwoNumbersRecursive(ListNode* l1, ListNode* l2, int carry) {
        if (l1 == NULL && l2 == NULL && carry == 0) {
            return NULL; // Base case: no more digits and no carry
        }
        int sum = carry;
        if (l1 != NULL){
            sum += l1->val;
            l1 = l1->next; // Move to the next node in l1
        }
        if (l2 != NULL){
            sum += l2->val;
            l2 = l2->next; // Move to the next node in l2
        }
        ListNode* resultNode = new ListNode(sum % 10); // Create a new node with the digit part of sum
        carry = sum / 10; // Update carry for next recursion
        // Recursively call for the next nodes and carry
        resultNode->next = addTwoNumbersRecursive(l1, l2, carry);
        return resultNode;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNumbersRecursive(l1, l2, 0);
    }
};
