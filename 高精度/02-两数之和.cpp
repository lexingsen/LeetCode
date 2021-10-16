struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 && !l2) {
            return l1;
        }
        if (!l1&& l2) {
            return l2;
        }
        if (!l1 && !l2) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        auto p = dummy;
        int carry = 0;
        while (l1 || l2) {
            int fa = l1 ? l1->val : 0;
            int fb = l2 ? l2->val : 0;
            int sum = fa + fb + carry;
            carry = sum / 10;
            p->next = new ListNode(sum % 10, nullptr);
            p = p->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry) {
            p->next = new ListNode(carry, nullptr);
        }
        return dummy->next;
    }
};