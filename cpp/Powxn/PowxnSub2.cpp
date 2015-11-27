/* 原先没有单独exp，Time limit exceeded
 * 添加unsigned int exp=n, 即可
 */
 
class Solution {
public:
    double myPow(double x, int n) {
        bool sign = true;
        unsigned int exp = n;
        double result = 1;
        if (n<0) {
            exp = -n;
            sign = false;
        }
        while (exp) {
            if (exp&1) {
                result *= x;
            }
            exp >>=1;
            x*=x;
        }
        return sign ? result : 1/result;
    }
};