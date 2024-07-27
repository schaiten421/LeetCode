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
    int widthOfBinaryTree(TreeNode* root) {
        long long width=INT_MIN;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            long long count=q.size();
            width=max(q.back().second-q.front().second+1,width);
            long long start=q.front().second;
            for(int i=0;i<count;i++){
                TreeNode* curr=q.front().first;
                long long idx=q.front().second-start;
                q.pop();
                
                if(curr->left!=NULL)q.push({curr->left,2*idx+1});
                if(curr->right!=NULL)q.push({curr->right,2*idx+2});
            }
        }
        return width;
    }
};