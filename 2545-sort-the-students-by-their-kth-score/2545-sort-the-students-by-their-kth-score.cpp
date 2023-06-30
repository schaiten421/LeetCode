class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int row=score.size();
        for(int i=0;i<row;i++){
            int res=0,index;
            for(int j=i;j<row;j++){
                if(score[j][k]>res){
                    res=score[j][k];
                    index=j;
                }
            }
            swap(score[i],score[index]);
        }
        return score;
    }
};