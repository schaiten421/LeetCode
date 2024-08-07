class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty() || asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top()==abs(asteroids[i])){
                    st.pop();
                }
                else if(st.empty() || st.top()<0){
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> result(st.size());
        for(int i=result.size()-1;i>=0;i--){
            result[i]=st.top();st.pop();
        }
        return result;
    }
};