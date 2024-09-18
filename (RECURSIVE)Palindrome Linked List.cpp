class Solution {
private:
    bool checkPalindrome(ListNode*& front, ListNode* current) {
        if (current == NULL) return true; // Reached the end of the list
        // Recurse to the end of the list
        bool isPal = checkPalindrome(front, current->next);
   if (isPal == false) return false; //  return if any part is not a palindrome

        // Compare values as the stack unwinds
        isPal = (front->val == current->val);
        front = front->next; // Move the front pointer forward for the next call's comparison

        return isPal;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* front = head;
        return checkPalindrome(front, head);
    }
};
