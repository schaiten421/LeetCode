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
    void f(TreeNode* root,int &ans,int &count,int k){
        if(!root)return;
        f(root->left,ans,count,k);
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        f(root->right,ans,count,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        int count=0;
        f(root,ans,count,k);
        return ans;
    }
};