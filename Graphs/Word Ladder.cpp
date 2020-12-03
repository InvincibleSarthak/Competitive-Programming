class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int ans = 0;
        
        map<string,vector<string>>dict;
        int n = beginWord.length();
        for(string s: wordList){
            for(int i=0;i<n;i++){
                string t = s.substr(0,i) + "*" + s.substr(i+1,n);
                dict[t].push_back(s);
            }
        }
        
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        
        map<string,bool>visited;
        
        while(!q.empty()){
            pair<string,int>temp = q.front();
            string curr = temp.first;
            int level = temp.second;
            visited[curr] = true;
            q.pop();
            
            for(int i=0;i<n;i++){
                string t = curr.substr(0,i)+"*"+curr.substr(i+1,n);
                for(auto it: dict[t]){
                    if(!it.compare(endWord))  return level+1;
                    
                    if(!visited[it]){
                        q.push({it,level+1});
                    }
                }
            }
        }
        return 0;
    }
};
