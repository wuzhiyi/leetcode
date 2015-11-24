/* 双下标
 * 第一个下标pos是待输出的，另一个下标找不同于pos的第一个元素
 * 注意限定条件，当数组元素个数小于2时
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        if (n<2) {
            return n;
        }
        for (int i=0; i<n; i++) {
            nums[pos++] = nums[i];
            while (nums[i] == nums[i+1]) {
                i++;
            }
        }
        return pos;
    }
};