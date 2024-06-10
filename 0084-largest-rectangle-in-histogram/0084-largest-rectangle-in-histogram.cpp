class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n=heights.size();
        int res=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int tp=st.top();
                st.pop();
                int curr=heights[tp]*(st.empty()?i:i-st.top()-1);
                res=max(res,curr);
                
            }
            st.push(i);
        }
        while(!st.empty()){
            int tp=st.top();
            st.pop();
            int curr=heights[tp]*(st.empty()?heights.size():heights.size()-st.top()-1);
            res=max(res,curr);
        }
        return res;
    }
};