struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        for (auto p = head; p;) {
            auto cur = dummy;
            auto next = p->next;
            while (cur->next && cur->next->val <= p->val) {
                cur = cur->next;
            }

            p->next = cur->next;
            cur->next = p;
            p = next;
        }

        return dummy->next;
    }
};