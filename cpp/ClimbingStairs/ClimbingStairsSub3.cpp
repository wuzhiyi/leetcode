/* 用for结构构造Fibonacci数列
 */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n+1);
        f[0]=1; f[1]=1;
        for (int i=2; i<=n; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[n];
    }
};