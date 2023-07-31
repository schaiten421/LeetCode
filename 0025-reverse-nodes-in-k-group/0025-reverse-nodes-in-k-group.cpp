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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)return head;
        ListNode* cursor = head;
        for(int i = 0; i < k; i++){
            if(cursor == nullptr) return head;
            cursor = cursor->next;
        }
        ListNode *curr=head,*prev=NULL,*nex=NULL;
        int count=0;
        while(count<k && curr!=NULL){
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
            count++;
        }
        if(nex!=NULL){
            ListNode *rest_head=reverseKGroup(nex,k);
            head->next=rest_head;
        }
        return prev;
        
    }
};