/* 1. 负数不能为 palindrome
 * 2. 翻转x，判断是否等于x
 */

class Solution {
private:
    int reverse(int x) {
        int rev = 0;
        while (x>0) {
            rev = rev*10 + x%10;
            x /= 10;
        }
        return rev;
    }
public:
    bool isPalindrome(int x) {
        return (x>=0 && x==reverse(x));
    }
};