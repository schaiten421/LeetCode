/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void parent_check(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent){
        if(root==NULL)return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *curr=q.front();
            q.pop();
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            } 
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        parent_check(root,parent);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=1;
        queue<TreeNode*> q;
        q.push(target);
        int level=0;
        while(!q.empty()){
            int s=q.size();
            if(level++==k)break;
            for(int i=0;i<s;i++){
                TreeNode* curr=q.front(); q.pop();
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=1;
                    q.push(curr->left);
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=1;
                    q.push(curr->right);
                }
                if(parent[curr] && !visited[parent[curr]]){
                    visited[parent[curr]]=1;
                    q.push(parent[curr]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* c=q.front(); q.pop();
            ans.push_back(c->val);
        }
        return ans;
    }
};