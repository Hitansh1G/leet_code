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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummy=new ListNode();
        ListNode*p=dummy;
        int carry=0,sum=0;
        while(l1 || l2 || carry){
            int x=l1?l1->val:0;
            int y=l2?l2->val:0;
            sum=x+y+carry;
            ListNode*n=new ListNode(sum%10);
            p->next=n;
            p=p->next;
            carry=sum/10;
            l1=l1?l1->next:NULL;
            l2=l2?l2->next:NULL;
        }
       return dummy->next;      
      }
};