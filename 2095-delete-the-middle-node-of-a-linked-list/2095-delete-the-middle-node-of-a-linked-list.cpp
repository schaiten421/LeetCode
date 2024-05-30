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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL || head->next==NULL) return NULL;
        ListNode* curr=head;
        int cnt=0;
        while(curr!=NULL){
            curr=curr->next;
            cnt++;
        }
        cnt=cnt/2;
        curr=head;
        for(int i=0;i<cnt-1;i++){
            curr=curr->next;
        }
        ListNode* temp=curr->next;
        curr->next=curr->next->next;
        delete(temp);
        return head;
        
    }
};