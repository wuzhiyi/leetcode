/* 若n为2的次方，则(n-1)一定为1111...， n&(n-1)一定为0
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n <= 0 ? false : (n & (n-1))==0;
    }
};