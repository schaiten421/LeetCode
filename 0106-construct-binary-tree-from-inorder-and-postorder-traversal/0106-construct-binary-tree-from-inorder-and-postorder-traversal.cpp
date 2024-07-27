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
    int post;
    TreeNode* f(vector<int>& inorder, vector<int>& postorder,int is,int ie){
        if(is>ie)return NULL;
        TreeNode* root=new TreeNode(postorder[post--]);
        int i;
        for(i=is;i<=ie;i++){
            if(inorder[i]==root->val){
                break;
            }
        }
        root->right=f(inorder,postorder,i+1,ie);
        root->left=f(inorder,postorder,is,i-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post=postorder.size()-1;
        return f(inorder,postorder,0,postorder.size()-1);
    }
};