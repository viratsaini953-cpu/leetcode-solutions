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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* temp=head;
        int c=0;
        ListNode* head1 = NULL;
        ListNode* tail = NULL;
        head1=NULL;
        while(temp!=NULL){
            if(temp->val==0){
                if(c){
                    ListNode* newnode=new ListNode(c);
                    if (head1 == NULL) {
                        head1 = newnode;
                        tail = newnode;
                    }
                    else {
                        tail->next = newnode;
                        tail = newnode;
                    }
                }
                c=0;
            }
            else{
                c+=temp->val;
            }
            temp=temp->next;
        }
        return head1;
    }
};