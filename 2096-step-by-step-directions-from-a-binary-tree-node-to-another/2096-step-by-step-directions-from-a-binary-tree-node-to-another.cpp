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
    TreeNode* lca(TreeNode* root,int s,int d){
        if(root==NULL || root->val==s || root->val==d)return root;
        TreeNode* left=lca(root->left,s,d);
        TreeNode* right=lca(root->right,s,d);
        if(left==NULL)return right;
        else if(right==NULL)return left;
        else return root;
    }
    bool f(TreeNode* root,int a,string &s){
        if(root==NULL)return 0;
        if(root->val==a){
            return 1;
        }
        s+='L';
        if(f(root->left,a,s)){
            return true;
        }
        s.pop_back();
        s+='R';
        if(f(root->right,a,s)){
            return true;
        }
        s.pop_back();
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lc=lca(root,startValue,destValue);
        string s="";
        string t="";
        f(lc,startValue,s);
        f(lc,destValue,t);
        string directions;
        directions.append(s.size(),'U');
        directions.append(t);
        return directions;
    }
};