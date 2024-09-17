class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        // Continue until the two pointers meet or both become null
        while(ptrA != ptrB){
            // If ptrA reaches the end of list A, redirect it to the beginning of list B
            if (ptrA == NULL){
                ptrA = headB;
            }else{
                ptrA = ptrA->next;
            }// If ptrB reaches the end of list B, redirect it to the beginning of list A
            if(ptrB == NULL){
                ptrB = headA;
            }else{
                ptrB = ptrB->next;
            }
        }
        // Either both pointers are null (no intersection) or both point to the intersection node
        return ptrA;
    }
};
