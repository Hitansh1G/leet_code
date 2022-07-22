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
    ListNode* partition(ListNode* head, int x) {
        vector<int>a;
        vector<int>b;
        ListNode* temp = head;
        while(head!=NULL){
            if(head->val < x){
                a.push_back(head->val);
            }
            else{
                b.push_back(head->val);
            }
            head = head->next;
        }
        head = temp;
        for(int i=0 ; i<a.size() ; i++){
            head->val=a[i];
            head = head->next;
        }
        for(int i=0 ; i<b.size() ; i++){
            head->val=b[i];
            head = head->next;
        }
        head = temp;
        return head;
    }
};