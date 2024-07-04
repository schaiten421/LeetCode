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
        head=head->next;
        ListNode* temp=new ListNode(0);
        ListNode* head2=temp;
        while(head->next!=NULL){
            if(head->val==0){
                temp->next=new ListNode(0);
                temp=temp->next;
            }
            else{
                temp->val+=head->val;
            }
            
            head=head->next;
        }
        return head2;
    }
};