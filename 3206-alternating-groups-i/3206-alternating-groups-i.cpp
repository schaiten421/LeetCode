class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n=colors.size(),i=1;
        int cnt=0;
        while(i<=n){
            if(colors[i%n]!=colors[i-1] && colors[i%n]!=colors[(i+1)%n]){
                cnt++;
            }
            i++;
        }
        return cnt;
    }
};