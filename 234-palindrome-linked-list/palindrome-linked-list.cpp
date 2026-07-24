class Solution {
public:
    bool isPalindrome(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* pre = NULL;
        ListNode* cur = slow->next;

        while (cur) {
            ListNode* n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }

        ListNode* first = head;
        ListNode* second = pre;

        while (second) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};