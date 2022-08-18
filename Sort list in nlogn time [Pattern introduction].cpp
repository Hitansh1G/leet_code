#include "../crio/cpp/ds/ListNode/ListNode.hpp"
/**
 * Definition for singly-linked list.
 * class ListNode {
 *   int val;
 *   ListNode* next;
 *   ListNode(int x) { val = x, next(NULL)}
 * }
 */

class SortList {
  public:
    // TODO: CRIO_TASK_MODULE_L1_PROBLEMS
    // Your implementation goes here
      ListNode* mergelist(ListNode *l1, ListNode *l2){
        ListNode *ptr = new ListNode(0);
        ListNode *curr = ptr;
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                curr -> next = l1;
                l1 = l1 -> next;
            }
            else{
                curr -> next = l2;
                l2 = l2 -> next;
            }
        curr = curr ->next;
        }
        if(l1 != NULL){
            curr -> next = l1;
            l1 = l1->next;
        }
        
        if(l2 != NULL){
            curr -> next = l2;
            l2 = l2 ->next;
        }
        
        return ptr->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL)
            return head;
        ListNode *temp = NULL;
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast !=  NULL && fast -> next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast ->next ->next;   
        }  
        temp -> next = NULL;
        ListNode* l1 = sortList(head);    
        ListNode* l2 = sortList(slow);    
        
        return mergelist(l1, l2);         
            
    }
};



/* 
Crio Methodology

Milestone 1: Understand the problem clearly
1. Ask questions & clarify the problem statement clearly.
2. Take an example or two to confirm your understanding of the input/output & extend it to test cases
Milestone 2: Finalize approach & execution plan
1. Understand what type of problem you are solving.
     a. Obvious logic, tests ability to convert logic to code
     b. Figuring out logic
     c. Knowledge of specific domain or concepts
     d. Knowledge of specific algorithm
     e. Mapping real world into abstract concepts/data structures
2. Brainstorm multiple ways to solve the problem and pick one
3. Get to a point where you can explain your approach to a 10 year old
4. Take a stab at the high-level logic & write it down.
5. Try to offload processing to functions & keeping your main code small.
Milestone 3: Code by expanding your pseudocode
1. Make sure you name the variables, functions clearly.
2. Avoid constants in your code unless necessary; go for generic functions, you can use examples for your thinking though.
3. Use libraries as much as possible
Milestone 4: Prove to the interviewer that your code works with unit tests
1. Make sure you check boundary conditions
2. Time & storage complexity
3. Suggest optimizations if applicable
*/