/*
class ListNode {
    public:
	int val;
	ListNode* next;

	ListNode() {}

	ListNode(int x) {                      
	    val = x;                       
	    next = NULL;
	}
};
*/
#include "../crio/cpp/ds/ListNode/ListNode.hpp"

ListNode* reverseList(ListNode* head){
    if(head == NULL) return head;
    ListNode* ptr, *fptr, *prev;
    ptr = head;
    fptr = ptr->next;
    ptr-> next = NULL;
    while(fptr != NULL){
        prev = ptr;
        ptr= fptr;
        fptr = fptr->next;
        ptr->next = prev;
    }
    return ptr;
}
ListNode* sumLists2(ListNode* l1 , ListNode* l2) {
    ListNode* head = new ListNode();
    ListNode* ptr = head;
    l1 = reverseList(l1);
    l2 = reverseList(l2);
    int carry = 0;
    while(l1!=NULL && l2!=NULL){ 
        ptr->next = new ListNode();
        ptr = ptr->next;
        ptr->val = l1->val + l2->val  + carry;
        carry = ptr->val/10;
        ptr->val = ptr->val % 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while(l1!=NULL){ 
        ptr->next = new ListNode();
        ptr = ptr->next;
        ptr->val = l1->val + carry;
        carry = ptr->val/10;
        ptr->val = ptr->val % 10;
        l1 = l1->next;
    }
    while(l2!=NULL){ 
        ptr->next = new ListNode();
        ptr = ptr->next;
        ptr->val = l2->val  + carry;
        carry = ptr->val/10;
        ptr->val = ptr->val % 10;
        l2 = l2->next;
    }
    if(carry!=0){
        ptr->next = new ListNode();
        ptr = ptr->next;
        ptr->val = carry;
    }
    head = reverseList(head->next);
    return head;
	// stack<int> s1,s2;
    // while(l1!=NULL){
    //     s1.push(l1->val);
    //     l1=l1->next;
    // }
    // while(l2!=NULL){
    //     s2.push(l2->val);
    //     l2=l2->next;
    // }
    // int carry=0;
    // ListNode* result=NULL;
    // while(s1.empty()==false || s2.empty()==false){
    //     int a=0,b=0;
    //     if(s1.empty()==false){
    //         a=s1.top();
    //         s1.pop();
    //     }
    //     if(s2.empty()==false){
    //         b=s2.top();
    //         s2.pop();
    //     }
    //     int total=a+b+carry;
    //     ListNode* temp=new ListNode();
    //     temp->val=total%10;
    //     carry=total/10;
    //     if(result==NULL){
    //         result=temp;
    //     }else{
    //         temp->next=result;
    //         result=temp;
    //     }
    // }
    // if(carry!=0){
    //     ListNode* temp=new ListNode();
    //     temp->val=carry;
    //     temp->next=result;
    //     result=temp;
    // }
    // return result;

}

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