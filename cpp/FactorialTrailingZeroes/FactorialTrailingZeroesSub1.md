/* 只是求trailing zeroes
 * 所以只要算出因子中5的个数
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n) {
            result += n/5;
            n /=5;
        }
        return result;
    }
};