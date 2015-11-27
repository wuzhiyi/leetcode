/* Fibonacci数列
 * 还是超时
 */

class Solution {
private:
    int fibonacci(int n) {
        if (n <= 2) {
            return n;
        }
        return fibonacci(n-1) + fibonacci(n-2);
    }
public:
    int climbStairs(int n) {
        return fibonacci(n);
    }
};