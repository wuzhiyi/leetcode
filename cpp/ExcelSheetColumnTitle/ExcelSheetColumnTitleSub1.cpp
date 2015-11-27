/* 必须从右往左判断
 */
 
class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n>0) {
            char ch = 'A' + (n-1)%26;
            result.insert(result.begin(), ch);
            n -= (n-1)%26;
            n /= 26;
        }
        return result;
    }
};