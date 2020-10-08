class Solution {
public:
    string reorganizeString(string S) {
        vector<int>arr(26,0);
        for(auto c: S){
            arr[c-'a'] += 100;
        }
        for(int i=0;i<26;i++){
            arr[i] += i;
        }
        sort(arr.begin(),arr.end());
        
        int n = S.length();
        string ans;
        for(int i=0;i<n;i++){
            ans.push_back('a');
        }
        int index = 1;
        for(int it: arr){
            int count = it/100;
            char temp = it%100 + 'a';
            if(count > (n+1)/2) return "";
            for(int i=0; i<count;i++){
                if(index>=n)    index=0;
                ans[index] = temp;
                index += 2;
            }
        }
        
        return ans;
    }
};
