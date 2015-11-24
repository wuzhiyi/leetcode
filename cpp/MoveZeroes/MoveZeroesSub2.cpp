/* 双标记
 * 有几个关键步骤，我一直没想出来
 */
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1, p2 = 0;
        int len = nums.size();
        for (; p1 <len && p2<len; p1++) {
            while (nums[p2] == 0) {
                p2++;
            }
            //避免数组全部为0，p2超出数组边界
            if (p2<len) {
                nums[p1] = nums[p2];
            } else {
                //key step
                p1--;
            }
            //key step
            p2++;
        }
        for (; p1<len; p1++) {
            nums[p1] = 0;
        }
    }
};