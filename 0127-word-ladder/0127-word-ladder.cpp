class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            string node=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(node==endWord) return steps;
            for(int i=0;i<node.size();i++){
                char original=node[i];
                for(char c='a';c<='z';c++){
                    node[i]=c;
                    if(st.find(node)!=st.end()){
                        st.erase(node);
                        q.push({node,steps+1});
                    }
                }
                node[i]=original;
            }
        }
        return 0;
    }
};