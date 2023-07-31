/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL)return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==slow)
                break;
        }
        fast=head;int count=1;
        while(!(fast==slow)){
            if(slow->next==NULL)
                return NULL;
            slow=slow->next;
            fast=fast->next;
            count++;
        }
        return fast;
    }
    
};