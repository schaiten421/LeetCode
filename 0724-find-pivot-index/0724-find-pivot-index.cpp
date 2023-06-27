class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size(),count=0;
        for(int i=1;i<n;i++)
            count+=nums[i];
        int left=0,right=count;
        for(int i=0;i<n;i++){
            if(left==right){
                return i;
            }
            else{
                left+=nums[i];
                if(i!=n-1)right-=nums[i+1];
            }
        }
        return -1;
    }
};