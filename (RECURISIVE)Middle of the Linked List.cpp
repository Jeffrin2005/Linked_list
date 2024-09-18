class Solution {
private:
    //  function to count nodes
    int countNodes(ListNode* node){
        if(node == NULL) return 0;
        return 1 + countNodes(node->next);
    }
    //function to find the middle node
    ListNode* findMiddle(ListNode* node, int& current, int middle) {
        if(node == NULL) return NULL;
        if(current == middle) return node;
        current++;
        return findMiddle(node->next, current, middle);
    }
    
public:
    ListNode* middleNode(ListNode* head) {
        int totalNodes = countNodes(head);
        int middleIndex = totalNodes / 2;  // This gives the second middle in case of even number of nodes
        int start = 0;
        return findMiddle(head, start, middleIndex);
    }
};
