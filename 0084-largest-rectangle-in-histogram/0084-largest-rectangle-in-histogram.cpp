class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res=0;
        for(int i=0;i<heights.size();i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                int tp=s.top();
                s.pop();
                int curr=heights[tp]*(s.empty()?i:(i-s.top()-1));
                res=max(res,curr);
            }
            s.push(i);
        }
        while(s.empty()==false){
            int tp=s.top();
            s.pop();
            int curr=heights[tp]*(s.empty()?heights.size():(heights.size()-s.top()-1));
            res=max(res,curr);
        }
        return res;
    }
};