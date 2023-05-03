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
    ListNode* sortList(ListNode* head) {
        ListNode* ptr=head;
        vector<int> v;
        while(ptr!=NULL){
            v.push_back(ptr->val);
            ptr=ptr->next;
        }
        ptr=head;
        sort(v.begin(),v.end());

        int i = 0 ;

        while(ptr!=NULL){
            ptr->val=v[i++];
            ptr=ptr->next;
        }
        v.clear();
        return head;

    }
};