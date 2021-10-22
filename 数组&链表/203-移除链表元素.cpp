struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        while (cur) {
            while (cur && cur->val == val) {
                ListNode* next = cur->next;
                pre->next = next;
                delete cur;
                cur = next;
            }
            
            if (!cur) {
                break;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};