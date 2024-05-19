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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto it=q.front();
            TreeNode* curr=it.first;
            int level=it.second;
            q.pop();
            if(mp.find(level)==mp.end())mp[level]=curr->val;
            if(curr->right!=NULL)q.push({curr->right,level+1});
            if(curr->left!=NULL)q.push({curr->left,level+1});
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};