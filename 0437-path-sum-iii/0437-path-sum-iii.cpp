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
    int cnt=0;
    void f(TreeNode* root,int targetSum,vector<int>& path){
        if(!root)return;
        path.push_back(root->val);
        f(root->left,targetSum,path);
        f(root->right,targetSum,path);
        long long f=0;
        for(int i=path.size()-1;i>=0;i--){
            f+=path[i];
            if(f==targetSum){
                cnt++;
            }
        }
        path.pop_back();
    }
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        f(root,targetSum,path);
        return cnt;
    }
};