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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> iStack;
        iStack.push(root);
        
        while(!iStack.empty()){
            TreeNode* currNode=iStack.top();
            iStack.pop();
            if(currNode!=NULL){
                v.push_back(currNode->val);
                iStack.push(currNode->right);
                iStack.push(currNode->left);
            }
        }
        return v;
    }
};