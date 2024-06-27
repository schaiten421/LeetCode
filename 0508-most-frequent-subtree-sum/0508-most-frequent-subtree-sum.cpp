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
    map<int,int> mpp;
    int maxfreq=0;
    int f(TreeNode* root,int sum){
        if(root==NULL)return 0;
        sum+=root->val+f(root->left,sum)+f(root->right,sum);
        mpp[sum]++;
        if(mpp[sum]>maxfreq){
            maxfreq=mpp[sum];
        }
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(root==NULL)return {};
        f(root,0);
        vector<int> ans;
        for(auto it:mpp){
            if(it.second==maxfreq)ans.push_back(it.first);
        }
        return ans;
    }
};