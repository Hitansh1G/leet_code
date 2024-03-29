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
        ListNode *curr = head;
        vector<ListNode *> ans;
        while (curr != NULL){
            ans.push_back(curr);
            curr = curr->next;
        }
        int start = 0;
        int end = ans.size() - 1;
        while(start < end){
            ans[start]->next = ans[end];
            ans[end]->next = ans[start + 1];
            start++;
            end--;
        }
        ans[start]->next = NULL;
    }
};