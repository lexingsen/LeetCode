struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 && !l2) {
            return l1;
        }
        if (!l1 && !l2) {
            return nullptr;
        }
        if (!l1 && l2) {
            return l2;
        }

        ListNode* dummy = new ListNode(-1, nullptr);
        auto p = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        } 

        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }

        return dummy->next;
    }
};