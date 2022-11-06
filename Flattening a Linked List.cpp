/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   auto comp = [&](Node *a, Node *b) {
        return a->data > b->data;
   };
   
   priority_queue<Node*,vector<Node*>, decltype(comp)> pq(comp);
   Node* it=root;
   while(it){
       pq.push(it);
       it=it->next;
   }
   Node* ans=NULL,*itr=NULL;
   while(!pq.empty()){
       Node* node=pq.top();
       if(ans==NULL) {
           ans=node;
           itr=node;
       }
       else{
           ans->bottom=node;
           ans=ans->bottom;
       }
       pq.pop();
       if(node->bottom) pq.push(node->bottom);
   }
   return itr;
}
