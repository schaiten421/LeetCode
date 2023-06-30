class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row=mat.size(),column=mat[0].size();
        vector<pair<int,int>> v;
        for(int i=0;i<row;i++){
            int freq=0;
            for(int j=0;j<column;j++){
                if(mat[i][j]==1){freq++;}
                else{break;}
            }
            v.push_back({freq,i});
        }
        sort(v.begin(),v.end());
        vector<int> va;
        for(int i=0;i<k;i++){
            va.push_back(v[i].second);
        }
        return va;
    }
};