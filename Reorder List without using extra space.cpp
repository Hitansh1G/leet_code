/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
       if (head->next==NULL) return;
        
        ListNode *slow = head, *fast = head->next;
        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *mid = slow->next;
        slow->next = NULL;
        ListNode *prev = NULL, *curr = mid, *nxt = mid->next;
        while (nxt!=NULL) {
            curr->next = prev;
            prev = curr;
            curr = nxt;
            nxt = nxt->next;
        }
        curr->next = prev;
        mid = curr;
        ListNode* p = head;
        ListNode* q = mid;
        while (q) {
            ListNode *pp = p, *qq = q;
            p = p->next; q = q->next;
            pp->next = qq; qq->next = p;
    }
    }
};