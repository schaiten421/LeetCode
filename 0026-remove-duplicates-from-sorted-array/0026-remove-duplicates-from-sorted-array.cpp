class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int l=0,r=1,size=nums.size(),k=1;
        while(r<size){
            if(nums[l]!=nums[r]){
                nums[l+1]=nums[r];
                l++;
            }
            r++;
        }
        return l+1;
    }
};