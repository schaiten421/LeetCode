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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==NULL ||head->next->next==NULL)return {-1,-1};
        ListNode* prev=head;
        ListNode* curr=head->next;
        ListNode* nex=head->next->next;
        int cnt=1,c=0;
        vector<int> ind;
        while(nex!=NULL){
            if((prev->val<curr->val && curr->val>nex->val)|| (curr->val<prev->val && 
                                                             curr->val<nex->val)){
                ind.push_back(cnt);
                c++;
            }
            prev=curr;
            curr=nex;
            nex=nex->next;
            cnt++;
        }
        if(c==0 || c==1)return {-1,-1};
        sort(ind.begin(),ind.end());
        int maxi=ind[c-1]-ind[0];
        int mini=INT_MAX;
        for(int i=1;i<c;i++){
            mini=min(mini,ind[i]-ind[i-1]);
        }
        return {mini,maxi};
    }
};