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
    int pre=0;
    TreeNode* f(vector<int>& preorder, vector<int>& inorder,int is,int ie){
        if(is>ie)return NULL;
        TreeNode* root=new TreeNode(preorder[pre++]);
        int i;
        for(i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                break;
            }
        }
        root->left=f(preorder,inorder,is,i-1);
        root->right=f(preorder,inorder,i+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return f(preorder,inorder,0,inorder.size()-1);
    }
};