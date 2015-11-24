/* 两个标记，i标记正位，pt按顺序标记非0元素，将pt赋值给i
 * 注意边界
 * 当input=[0,0]时，output=[0,0]，但是leetcode报错
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        if (len<2) {
            return;
        }
        int pt = 0;
        int cnt = 0;
        int i = 0;
        for (; pt<len;) {
            for (; nums[pt] == 0;) {
                pt++;
                cnt++;
            }
            if (pt>len) {
                break;
            }
            nums[i++] = nums[pt++];
        }
        for (; i<len; i++) {
            nums[i] = 0;
        }
    }
};