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


ListNode* partition(ListNode* head , int x) {

    // ListNode* smallerhead = NULL, *smallertail=NULL;
    // ListNode* greaterhead = NULL, *greatertail=NULL;
    // ListNode* equalhead = NULL, *equaltail=NULL;

    // while(head!=NULL){
    //     if(head->val == x){
    //         if(equalhead == NULL){
    //             equalhead=head;
    //             equaltail=head;
    //         }
    //         else{
    //             equaltail->next=head;
    //             equaltail=head;
    //         }
    //     }
    //     else if(head->val<x){
    //         if(smallerhead==NULL){
    //             smallerhead=head;
    //             smallertail=head;
    //         }
    //         else{
    //             smallertail->next = head;
    //             smallertail=smallertail->next;
    //         }
    //     }
    //     else{
    //         if(greaterhead==NULL){
    //             greaterhead=head;
    //             greatertail=head;
    //         }
    //         else{
    //             greatertail->next = head;
    //             greatertail=smallertail->next;
    //         }
    //     }
    //     head = head->next;
    // }
    // if(greatertail!=NULL){
    //     greatertail->next=NULL;
    // }
    // if(smallerhead==NULL){
    //     if(equalhead==NULL){
    //         return greaterhead;
    //     }
    //     equaltail->next = greaterhead;
    //     return equalhead;
    // }
    // if(equalhead==NULL){
    //     smallerhead->next = greaterhead;
    //     return smallerhead;
    // }
    // smallerhead->next = equalhead;
    // equalhead->next = greaterhead;
    // return smallerhead;
    ListNode*smallerHead = NULL, *smallerLast = NULL;
    ListNode*greaterLast = NULL, *greaterHead = NULL;
    ListNode *equalHead = NULL, *equalLast = NULL;
    while (head != NULL) {
        if (head->val == x) {
            if (equalHead == NULL)
                equalHead = equalLast = head;
            else {
                equalLast->next = head;
                equalLast = equalLast->next;
            }
        }
        else if (head->val < x) {
            if (smallerHead == NULL)
                smallerLast = smallerHead = head;
            else {
                smallerLast->next = head;
                smallerLast = head;
            }
        }
        else {
            if (greaterHead == NULL)
                greaterLast = greaterHead = head;
            else {
                greaterLast->next = head;
                greaterLast = head;
            }
        }
  
        head = head->next;
    }
    if (greaterLast != NULL)
        greaterLast->next = NULL;
    if (smallerHead == NULL) {
        if (equalHead == NULL)
            return greaterHead;
        equalLast->next = greaterHead;
        return equalHead;
    }
    if (equalHead == NULL) {
        smallerLast->next = greaterHead;
        return smallerHead;
    }
    smallerLast->next = equalHead;
    equalLast->next = greaterHead;
    return smallerHead;
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