class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> ans;
        left[0]=nums[0];right[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            left[i]*=(nums[i]*left[i-1]);
            right[n-i-1]*=(nums[n-i-1]*right[n-i]);
        }
        // 1 2 6 24
        // 24 24 12  4
        for(int i=0;i<n;i++){
            if(i==0)ans.push_back(right[i+1]);
            else if(i==n-1) ans.push_back(left[n-2]);
            else ans.push_back(left[i-1]*right[i+1]);
        }
        return ans;
    }
};