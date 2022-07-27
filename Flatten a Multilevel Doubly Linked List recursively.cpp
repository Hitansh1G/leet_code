/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flattent(Node *node){
        if (node == NULL)
            return node;
        Node* childNode = node->child;
        Node* nextNode = node->next;
        Node* childLast = flattent(childNode);
        Node* nextLast = flattent(nextNode);
        node->child = NULL;
        if (childLast != NULL)
        {
            node->next = childNode;
            childNode->prev = node;
            node = childLast;
        }
        if (nextLast != NULL)
        {
            node->next = nextNode;
            nextNode->prev = node;
            node = nextLast;
        }
        return node;
    }

    Node* flatten(Node* head) {
        Node *res = head;
        flattent(head);
        return res;
    }
};