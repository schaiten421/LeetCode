class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string s) {
        int n=s.length();
        vector<int> index(n),result;
        for(int i=0;i<n;i++){
            index[i]=i;
        }
        sort(index.begin(),index.end(),[&](int a,int b){return positions[a]<positions[b];});
        stack<int> st;
        for(auto curr:index){
            if(s[curr]=='R'){
                st.push(curr);
            }
            else{
                while(!st.empty() && healths[curr]>0){
                    int topindex=st.top();
                    st.pop();
                    
                    if(healths[topindex]>healths[curr]){
                        healths[topindex]--;
                        st.push(topindex);
                        healths[curr]=0;
                    }else if(healths[topindex]<healths[curr]){
                        healths[curr]--;
                        healths[topindex]=0;
                    }else{
                        healths[topindex]=0;
                        healths[curr]=0;
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(healths[i]>0){
                result.push_back(healths[i]);
            }
        }
        return result;
        
    }
};