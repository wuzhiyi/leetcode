/* 先去噪，只保留alpha或digit，且注意全部小写tolower
 * 然后头尾两个标记判断即可
 */

class Solution {
private:
    string removeNoise(string s) {
        string ret;
        for (int i=0; i<s.size(); i++) {
            if (isdigit(s[i]) || isalpha(s[i])) {
                ret.push_back(tolower(s[i]));
            }
        }
        return ret;
    }
public:
    bool isPalindrome(string s) {
        s = removeNoise(s);
        for (int i=0; i<s.size()/2; i++) {
            if (s[i] != s[s.size()-i-1]) {
                return false;
            }
        }
        return true;
    }
};