class Solution {
public:
    bool isValid(string s) {
        stack<int> s1;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                s1.push(s[i]);
            }
            if(s[i] == ')'){
                if(s1.size() == 0)   return false;
                if(s1.top() == '(') s1.pop();
                else    return false;
            }
            if(s[i] == '}'){
                if(s1.size() == 0)   return false;
                if(s1.top() == '{') s1.pop();
                else    return false;
            }
            if(s[i] == ']'){
                if(s1.size() == 0)   return false;
                if(s1.top() == '[') s1.pop();
                else    return false;
            }
        }
        if(s1.size() != 0)   return false;
        return true;
    }
};
