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
    int sum=0;
    void solve(TreeNode* root,TreeNode* parent,TreeNode* gp){
        if(root==NULL)return;
        if(gp && gp->val%2==0)sum+=root->val;
        solve(root->left,root,parent);
        solve(root->right,root,parent);
    }
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        solve(root,NULL,NULL);
        return sum;
        
    }
};