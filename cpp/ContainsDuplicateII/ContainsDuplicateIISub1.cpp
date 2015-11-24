/* 双循环
 * 最直接的，但是 Time Limit Exceeded
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int len = nums.size();
        if (k>len) {
            k %= len;
        }
        for (int i=0; i<len; i++) {
            for (int j=i+1; j<i+k; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};