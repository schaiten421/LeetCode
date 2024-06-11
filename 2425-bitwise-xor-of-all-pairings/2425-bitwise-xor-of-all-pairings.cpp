class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int a=0;
        if(nums1.size()%2==1){
            for(int i=0;i<nums2.size();i++){
                a=a^(nums2[i]);
        }
        }
        if(nums2.size()%2==1){
        for(int i=0;i<nums1.size();i++){
            a=a^(nums1[i]);
        }}
        
        return a;
    }
};