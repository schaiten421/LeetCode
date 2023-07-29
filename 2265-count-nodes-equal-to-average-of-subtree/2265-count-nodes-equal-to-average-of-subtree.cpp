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
    void solve(TreeNode * root,int& count,int& tsum){
        if(root==NULL)return;
        
        count++; tsum+=root->val;
        
        solve(root->left,count,tsum);
        solve(root->right,count,tsum);
    }
    int averageOfSubtree(TreeNode* root) {
        
        if(root==NULL)return 0;
        int count=0;
        int tsum=0;
        
        solve(root,count,tsum);
        
        if(tsum/count==root->val)sum++;
        
        averageOfSubtree(root->left);
        averageOfSubtree(root->right);
        return sum;
    }
};