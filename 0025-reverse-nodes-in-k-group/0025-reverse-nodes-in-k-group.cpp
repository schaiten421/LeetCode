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
    ListNode* kNode(ListNode* temp,int k){
        k--;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* node1=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return node1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head, *nex=NULL, *prev=NULL;
        while(temp!=NULL){
            ListNode* kthNode=kNode(temp,k);
            if(kthNode==NULL){
                if(prev)prev->next=temp;
                break;
            }
            nex=kthNode->next;
            kthNode->next=NULL;
            ListNode* revNode=reverse(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prev->next=kthNode;
            } 
            prev=temp;
            temp=nex;
        }
        return head;
    }
};