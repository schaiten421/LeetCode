class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        stack<int> s;
        vector<string> v;
        int c=0;
        for(int i=1;i<=n;i++){
            if(target.size()<=c)break;
            if(target[c]==i){s.push(i);
            v.push_back("Push");
            c++;
            }
            else{
                v.push_back("Push");
                v.push_back("Pop");
            }
        }
        return v;
    }
};