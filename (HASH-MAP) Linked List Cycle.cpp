class Solution {
public:
    bool hasCycle(ListNode* head) {
         // Create an unordered_map to store visited nodes.
       map<ListNode*,bool>visited;
        ListNode* current = head;
        while(current != NULL){
            // If the current node is already in the map, a cycle exists.
            if(visited.find(current) != visited.end()){
                return true;
            }
            // Mark the current node as visited.
            visited[current] = true;
            // Move to the next node.
            current = current->next;
        }
        // No cycle detected.
        return false;
    }
};
