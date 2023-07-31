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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr=headA;
        int c1=0;
        while(curr!=NULL){
            curr=curr->next;
            c1++;
        }
        ListNode* curr1=headB;
        int c2=0;
        while(curr1!=NULL){
            curr1=curr1->next;
            c2++;
        }
        curr=headA,curr1=headB;
        for(int i=0;i<abs(c1-c2);i++){
                if(c1>c2)curr=curr->next;
                else curr1=curr1->next;
        }
        while(curr!=NULL && curr1!=NULL){
            if(curr==curr1)return curr;
            curr=curr->next;
            curr1=curr1->next;
        }
        return NULL;
        
    }
};