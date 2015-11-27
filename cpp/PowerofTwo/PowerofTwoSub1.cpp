/* 常规法
 * 求n%2, 若为0，n/=2.
 * 直到n%2!=0, 判断n==1
 * Time limit exceeded
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n%2 == 0) {
            n /= 2;
        }
        if (n != 1) {
            return false;
        }
        return true;
    }
};