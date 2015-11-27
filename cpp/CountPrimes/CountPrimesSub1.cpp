/* 建立一个映射，然后从2开始，找出质数，除去该质数的所有乘积，直到n
 */

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> map(n, true);
        int cnt = 0;
        for (int i=2; i*i<n; i++) {
            if (map[i]) {
                for (int j=i*i; j<n; j+=i) {
                    map[j] = false;
                }
            }
        }
        for (int l=2; l<n; l++) {
            if (map[l]) {
                cnt++;
            }
        }
        return cnt;
    }
};