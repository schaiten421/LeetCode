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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)return NULL;
        ListNode* curr=head;
        int cnt=1;
        while(curr->next!=NULL){
            curr=curr->next;
            cnt++;
        }
        ListNode* prev=head;
        int nr=k%cnt;
        for(int i=0;i<cnt-nr-1;i++){
            prev=prev->next;
        }
        curr->next=head;
        head=prev->next;
        prev->next=NULL;
        return head;
        
    }
};