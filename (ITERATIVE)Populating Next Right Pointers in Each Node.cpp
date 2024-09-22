class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        Node* current = root;
        // As long as there is a left child
        while(current->left != NULL) {
            Node* temp = current;
            while(temp != NULL){
                // Connect the children of the current node
                temp->left->next = temp->right;
                // Connect the right child to the next subtree's left child, if it exists
                if(temp->next != NULL) {
                    temp->right->next = temp->next->left;
                }

                // Move to the next node in the current level
                temp = temp->next;
            }

            // Move to the next level
            current = current->left;
        }

        return root;
    }
};
