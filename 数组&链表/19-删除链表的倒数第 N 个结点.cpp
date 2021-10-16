struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        int cnt = 0;
        auto p = head;
        while (p) {
            cnt++;
            p = p->next;
        }
        p = dummy;
        int k = cnt - n;
        while (k--) {
            p = p->next;
        }
        auto q = p->next;
        p->next = q->next;
        delete q;
        return dummy->next;
    }
};