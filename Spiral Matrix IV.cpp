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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        //make a matrix using linked list
        vector<vector<int>> mat(m, vector<int>(n, -1));

        
        int left = 0;
        int right = n-1 ;
        int top = 0;
        int bottom = m-1 ;
        while(left <= right && top <= bottom){
            if(top <= bottom){
                int i=left;
                while(head!=NULL && i<=right){
                    mat[top][i]=head->val;
                    i++;
                    head=head->next;
                }
                top++;
            }
            if(left <= right){
                int i=top;
                while(head!=NULL && i<=bottom){
                    mat[i][right]=head->val;
                    i++;
                    head=head->next;
                }
                right--;
            }
            if(top <= bottom){
                int i=right;
                while(head!=NULL && i>=left){
                    mat[bottom][i]=head->val;
                    i--;
                    head=head->next;
                }
                bottom--;
            }
            if(left <= right){
                int i=bottom;
                while(head!=NULL && i>=top){
                    mat[i][left]=head->val;
                    i--;
                    head = head->next;
                }
                left++;
            }
        }   
        return mat;
    }
};