class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        int maxsum=sum,r=cardPoints.size()-1;
        for(int i=0;i<k;i++){
            sum+=(cardPoints[r-i]-cardPoints[k-i-1]);
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};