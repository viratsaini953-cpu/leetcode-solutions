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
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int sr=0;
        int er=m-1;
        int sc=0;
        int ec=n-1;
        ListNode* temp=head;
        while(temp!=NULL && sr <= er && sc <= ec){
            //top
            for(int i=sc;i<=ec && temp != NULL;i++){
                ans[sr][i]=temp->val;
                temp=temp->next;
            }

            // right
            for(int i=sr+1;i<=er && temp != NULL;i++){
                ans[i][ec]=temp->val;
                temp=temp->next;
            }

            for(int i=ec-1;i>=sc && sr<er && temp != NULL;i--){
                ans[er][i]=temp->val;
                temp=temp->next;
            }

            for(int i=er-1;i>sr&& sc<ec && temp != NULL;i--){
                ans[i][sc]=temp->val;
                temp=temp->next;
            }
            ec--;
            sc++;
            er--;
            sr++;
        }
    return ans;
    }
};