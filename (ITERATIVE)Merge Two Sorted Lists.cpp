
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
           ListNode dummy; // Dummy node to act as the start of the merged list
        ListNode* current = &dummy; // Pointer to build the new list
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                current->next = list1; // Attach list1 node to merged list
                list1 = list1->next; // Move to the next element in list1
            }else{
                current->next = list2; // Attach list2 node to merged list
                list2 = list2->next; // Move to the next element in list2
            }
            current = current->next; // Move to the next position in merged list
        }
        // Attach the remaining elements of list1 or list2
        if (list1 != NULL) {
            current->next = list1;
        }else{
            current->next = list2;
        }

        return dummy.next; 
    }
};
