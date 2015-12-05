class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        int len = s.size();
        for (int i=0; i<len; i++) {
            if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
                stk.push(s[i]);
            } else {
                if (stk.empty()) {
                    return false;
                }
                if (stk.top()=='(' && s[i]==')') {
                    stk.pop();
                } else if (stk.top()=='[' && s[i]==']') {
                    stk.pop();
                } else if (stk.top()=='{' && s[i]=='}') {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }
        return stk.empty();
    }
};