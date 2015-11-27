class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        for (int i=0; i<s.size(); i++) {
            int n = s[i] - 'A' + 1;
            result = 26*result + n;
        }
        return result;
    }
};