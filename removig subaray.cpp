/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


void insert(ListNode * A, ListNode * B) {
    if (A -> next == NULL) {
        A -> next = B;
        B -> next = NULL;
    } else {
        ListNode * tmp = A -> next;
        A -> next = B;
        B -> next = tmp;
    }
}
ListNode * Solution::solve(ListNode * A, int B) {

    if (A == NULL) return A;
    vector < ListNode * > v;
    int i = 0;
    ListNode * itr = A;


    while (i < B) {
        v.push_back(itr);
        ListNode * tmp = itr -> next;
        itr -> next = NULL;
        itr = tmp;
        i++;
    }

    while (itr != NULL) {
        ListNode * tmp = itr -> next;
        insert(v[i % B], itr);
        i++;
        itr = tmp;
    }

    itr = v[0];
    while (itr -> next) {
        itr = itr -> next;
    }
    for (int i = 1; i < B; i++) {
        itr -> next = v[i];
        while (itr -> next) {
            itr = itr -> next;
        }
    }

    return v[0];

}