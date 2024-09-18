class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // Dummy node to simplify edge cases
        ListNode* current = dummyHead;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry != 0){
            int sum = carry; // Start with the carry from the previous iteration
            if (l1 != NULL) {
                sum += l1->val; // Add value from l1
                l1 = l1->next;  // Move to the next element in l1
            } if (l2 != NULL) {
                sum += l2->val; // Add value from l2
                l2 = l2->next;  // Move to the next element in l2
            } carry = sum / 10; // Update carry for next iteration
            current->next = new ListNode(sum % 10); // Create new node with the digit part of sum
            current = current->next; // Move to the next node
        }
        return dummyHead->next; // Return the next of dummyHead as the first node of the result list
    }               // LOGIC FOR   carry = sum / 10; AND current->next = new ListNode(sum % 10)
};
//  sum % 10: Extracting the Current Digit
// Purpose: To obtain the single digit that should be stored in the current node of the result linked list.
// Operation: The modulo operation (%) returns the remainder after division of one number by another.
// Why % 10?
// Since we're dealing with base-10 numbers, any sum of two digits (plus a possible carry) will be between 0 and 19:
// 0
// ≤
// sum
// ≤
// 9
// +
// 9
// +
// 1
// =
// 19
// 0≤sum≤9+9+1=19
// Using sum % 10 effectively extracts the least significant digit (the rightmost digit) of the sum, which is exactly the digit that should be placed in the current node.
// Examples:
// If sum = 7:
// 7
// %
// 10
// =
// 7
// (Store 7 in the current node)
// 7%10=7(Store 7 in the current node)
// If sum = 15:
// 15
// %
// 10
// =
// 5
// (Store 5 in the current node)
// 15%10=5(Store 5 in the current node)
// 2. carry = sum / 10: Determining the Carry-Over
// Purpose: To determine if there's a carry-over to the next higher digit.
// Operation: Integer division (/) divides one number by another and truncates any fractional part, effectively returning how many times the divisor fits into the dividend.
// Why / 10?
// In base-10, if the sum of two digits exceeds 9, it means there's a carry-over to the next higher place value.
// Using sum / 10 gives us the number of tens in the sum, which is either 0 or 1 (since the maximum sum is 19).
// Examples:
// If sum = 7:
// 7
// /
// 10
// =
// 0
// (No carry-over)
// 7/10=0(No carry-over)
// If sum = 15:
// 15
// /
// 10
// =
// 1
// (Carry-over of 1 to the next digit)
// 15/10=1(Carry-over of 1 to the next digit)
