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
    string f(TreeNode* root,unordered_map<string,int>& mpp,vector<TreeNode*>& ans){
        if(root==NULL)return "";
        string str="(";
        str+=f(root->left,mpp,ans);
        str+=to_string(root->val);
        str+=f(root->right,mpp,ans);
        str+=')';
        
        if(mpp[str]==1){
            ans.push_back(root);
        }
        mpp[str]++;
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int> mpp;
        vector<TreeNode*> ans;
        f(root,mpp,ans);
        return ans;
    }
};