class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      set<ListNode*>nodesInA;

        // Store all nodes from list A in the hash set
        ListNode* current = headA;
        while(current != NULL){
            nodesInA.insert(current);
            current = current->next;
        }
        // Check each node in list B; if it's found in the set, it's the intersection
        current = headB;
        while(current != NULL){
            if(nodesInA.find(current) != nodesInA.end()){
                return current;  // Intersection found
            }
            current = current->next;
        }

        return NULL;  // No intersection
    }
};
