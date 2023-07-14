class Solution {
public:
    int trap(vector<int>& height) {
        int s=height.size(),res=0;
        vector<int> lmax;
        vector<int> rmax(s);
        int l=INT_MIN,r=INT_MIN;
        for(int i=0;i<height.size();i++){
            l=max(l,height[i]);
            lmax.push_back(l);
        }
        // 0 1 1 2 2 2 2 3 3 3 3 3
        for(int i=height.size()-1;i>=0;i--){
            r=max(r,height[i]);
            rmax[i]=r;
        }
        // 1 2 2 2 3 3 3 3 3 3 3 3 
        //3 3 3 3 3 3 3 3 2 2 2 1
        for(int i=0;i<s;i++){
            res+=(min(lmax[i],rmax[i])-height[i]);
        }
        return res;
    }
};