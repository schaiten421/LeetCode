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
    TreeNode* dfs(unordered_map<int,vector<pair<int,bool>>>& parentToChildren,int val){
        TreeNode* node=new TreeNode(val);
        
        if(parentToChildren.find(val)!=parentToChildren.end()){
            for(auto &c:parentToChildren[val]){
                if(c.second){
                    node->left=dfs(parentToChildren,c.first);
                }
                else{
                    node->right=dfs(parentToChildren,c.first);
                }
            }
        }
        return node;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> nodes;
        unordered_set<int> children;
        unordered_map<int,vector<pair<int,bool>>> parentToChildren;
        
        for(auto it: descriptions){
            int p=it[0];
            int c=it[1];
            bool isleft=it[2];
            
            parentToChildren[p].push_back({c,isleft});
            nodes.insert(p);
            nodes.insert(c);
            children.insert(c);
        }
        
        int rootval=0;
        for(int node:nodes){
            if(!children.contains(node)){
                rootval=node;
                break;
            }
        }
        return dfs(parentToChildren,rootval);
    }
};