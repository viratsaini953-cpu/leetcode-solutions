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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;
        

        ListNode *l=head;
        for(int i=1;i<left-1;i++){
            l=l->next;
        }
        ListNode* lend=l;


        if(left==1){
            l=head;
        }
        else{
            l=l->next;
        }   

        ListNode *r=l;
        for(int j=left;j<right;j++){
            r=r->next;
        }
        ListNode*rend=r->next;;


        ListNode*temp=l;
        ListNode*curr=l;
        ListNode*t=l;
        temp=temp->next;
        
        int k = left;
        while(k<right){
            t=curr;
            curr=temp;
            temp=temp->next;
            curr->next=t;
            k++;
        }
        l->next = rend;
        if(left == 1){
            head = curr;
        }
        else{
            lend->next = curr;
        }
        return head;
    }
};