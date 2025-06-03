class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next==nullptr) {
            return false; 
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};