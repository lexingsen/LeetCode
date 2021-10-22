struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1, head);
        auto first = dummy->next;
        auto pre = dummy->next;
        auto cur = dummy->next->next;
        while (cur) {
            while (cur && cur->val == first->val) {
                ListNode* next = cur->next;
                pre->next = next;
                cur = next;
            }
            if (!cur) {
                break;
            }
            else if (cur->val != first->val) {
                first = cur;
                pre = cur;
            } else {
                cur = cur->next;
                pre = pre->next;
            }
            
        }
        return dummy->next;
    }
};