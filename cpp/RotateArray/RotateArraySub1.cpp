/* Time Limit Exceeded
 * rightwards使数组右移一位，k为调用rightwards次数
 * 但是当nums和k都很大的时候，超时
 */

class Solution {
public:
    void rightwards(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[n-1];
        for (int i=n-1; i>0; i--) {
            nums[i] = nums[i-1];
        }
        nums[0] = tmp;
    }

    void rotate(vector<int>& nums, int k) {
        if (k<0) {
            return;
        }
        for (int j=0; j<k; j++) {
            rightwards(nums);
        }
    }
};