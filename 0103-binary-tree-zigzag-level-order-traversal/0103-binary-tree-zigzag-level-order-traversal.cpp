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
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int s=q.size();
            vector<int> a(s);
            for(int i=0;i<s;i++){
                TreeNode *curr=q.front();
                q.pop();
                if(!level) a[i]=curr->val;
                else a[s-i-1]=curr->val;
                if(curr->left!=NULL)q.push(curr->left);
                if(curr->right!=NULL)q.push(curr->right);
            }
            ans.push_back(a);
            level=!level;
        }
        return ans;
    }
};


