class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int maxlen=0;
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int cnt=1;
                int n=it+1;
                while(st.find(n)!=st.end()){
                    cnt++;n++;
                }
                maxlen=max(maxlen,cnt); 
            }
        }
        return maxlen;
    }
};