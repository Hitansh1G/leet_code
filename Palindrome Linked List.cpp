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
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast)
            slow = slow->next;
        ListNode *node = slow;
        ListNode *last = nullptr;
        ListNode *next = nullptr;
        while(node){
            next = node->next;
            node->next = last;
            last = node;
            node = next;
        }
        node = last;
        while(node){
            if (node->val == head->val) node = node->next, head = head->next;
            else return false;
        }
        return true;
    }
};