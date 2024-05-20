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
    TreeNode* markparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_check,
                         int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target;
        while(!q.empty()){
            TreeNode* curr=q.front();
            if(curr->val==start)target=curr;
            q.pop();
            if(curr->left){
                parent_check[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent_check[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return target;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent_check;
        TreeNode* target=markparents(root,parent_check,start);
        
        unordered_map<TreeNode*,bool> visited;
        visited[target]=1;
        queue<TreeNode*> q;
        q.push(target);
        int time=0;
        while(!q.empty()){
            int s=q.size();
            time++; 
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=1;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=1;
                    q.push(curr->right);
                }
                if(parent_check[curr] && !visited[parent_check[curr]]){
                    visited[parent_check[curr]]=1;
                    q.push(parent_check[curr]);
                }
            }
        }
        return time-1;
    }
};