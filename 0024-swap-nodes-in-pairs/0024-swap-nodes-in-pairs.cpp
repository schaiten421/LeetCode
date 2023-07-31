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
    ListNode* swapPairs(ListNode* head) {
        ListNode * curr=head,*prev=NULL,*nex=NULL;
        int count=0;
        while(curr!=NULL && count<2){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            count++;    
        }
        if(nex!=NULL){
            ListNode *rest_head=swapPairs(nex);
            head->next=rest_head;
        }
        return prev;
    }
};