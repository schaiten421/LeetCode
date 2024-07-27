/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool reverse=false;
        while(!q.empty()){
            int count=q.size();
            stack<int> s;
            vector<int> temp;
            for(int i=0;i<count;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(reverse){
                    s.push(curr->val);
                }
                else{
                    temp.push_back(curr->val);
                }
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
            if(reverse){
                while(!s.empty()){
                    temp.push_back(s.top());
                    s.pop();
                }
            }
            ans.push_back(temp);
            reverse=!reverse;
        }
        return ans;
    }
};