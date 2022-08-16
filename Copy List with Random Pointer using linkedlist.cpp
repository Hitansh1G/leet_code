/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head){
            return NULL;
        }
        Node* list = new Node(head->val);
        Node* head2 = head;
        Node* list2 = list;
        Node* res = list;
        unordered_map<Node*, Node*> m;
        m.insert(make_pair(head, list));
        while(head->next){
            list->next = new Node(head->next->val);
            m.insert(make_pair(head->next, list->next));
            head = head->next;
            list = list->next;
        }
        m.insert(make_pair(head->next, list->next));
        while(head2->next){
            list2->random = m[head2->random];
            head2 = head2->next;
            list2 = list2->next;
        }
        list2->random = m[head2->random];
        return res;
    }
};

