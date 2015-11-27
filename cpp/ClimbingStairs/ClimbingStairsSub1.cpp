/* 二分法
 * 但是超时了
 */

class Solution {
public:
    int climbStairs(int n) {
        if (n > 1) {
            return climbStairs(n-1) + climbStairs(n-2);
        }
        return 1;
    }
};