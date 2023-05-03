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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
            return NULL;
		for (int i = 0; i < lists.size(); ++i) {
			if (!lists[i]){
				lists[i] = new ListNode(INT_MAX);
			}
			else {
				ListNode *pt = lists[i];
				while (pt->next) pt = pt->next;
				pt->next = new ListNode(INT_MAX);
			}
		}

		vector<ListNode*> pts(lists);
		ListNode preHead = ListNode(INT_MIN);
		ListNode *cur = &preHead;
		while (true) {
			int min = INT_MAX;
			int minLoc = -1;
			for (int i = 0; i < pts.size(); ++i) {
				if (pts[i]->val <= min) {
					min = pts[i]->val;
					minLoc = i;
				}
			}

			if (!pts[minLoc]->next) {
				cur->next = NULL;
				break;
			}
			cur->next = pts[minLoc];
			cur = cur->next;
			pts[minLoc] = pts[minLoc]->next;
		}
		return preHead.next;
	}
};