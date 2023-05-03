#include "../crio/cpp/ds/ListNode/ListNode.hpp"

/*
The ListNode class is implemented as follows:
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

// Implement your solution here
ListNode* insertIntoSortedCircularList(ListNode* head, int insertVal)
{
	if(head == NULL){
		ListNode* temp = new ListNode(insertVal);
		temp->next = temp;
		return temp;
	}
	ListNode* maxx = head ;
	ListNode* minn = head->next ;
	ListNode* node = head->next;

	while(node != head){
		if(node->val > node->next->val){
			maxx = node;
			minn = node->next;
		}
		node = node->next;
	}
	if(insertVal>= maxx->val || insertVal <=minn->val){
		ListNode* temp = new ListNode(insertVal);
		maxx->next = temp;
		temp->next = minn;
		return head;
	}
	else{
		ListNode* prev = minn ;
		node = minn->next;
		while(node!=minn){
			if(node->val >= insertVal && prev->val < insertVal){
				ListNode* temp = new ListNode(insertVal);
				prev->next = temp;
				temp->next = node;
				return head;
			}
			prev = node;
			node = node->next;
		}
	}

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