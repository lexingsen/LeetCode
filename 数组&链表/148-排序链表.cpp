struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

    ListNode* merge(ListNode* a, ListNode* b) {
        if (!b) {
            return a;
        }
        if (!a) {
            return b;
        }
        if (a->val <= b->val) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(b->next, a);
            return b;
        }
        
    }

    ListNode* mergeSort(ListNode* head) {
        if (!head->next) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* pre = nullptr;
        while (fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow指向第二个链表的第一个位置 
        // pre指向第一个链表的最后一个位置
        pre->next = nullptr;
        auto left = mergeSort(head);
        auto right = mergeSort(slow);
        return merge(left, right);
    }
    ListNode* sortList(ListNode* head) {
        return !head ? nullptr : mergeSort(head); 
    }
};