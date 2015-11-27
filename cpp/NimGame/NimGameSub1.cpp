/* 当n为4整数倍时，先手必输
 */

class Solution {
public:
    bool canWinNim(int n) {
        return !(n%4 == 0);
    }
};