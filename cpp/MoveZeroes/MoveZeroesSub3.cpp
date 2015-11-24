/* 双指针
 * p1找到第一个0，然后p2=p1
 * p2找到p1后第一个不为0的数，赋值给p1，当p2超出边界时结束
 * p1将数组其后的数全部赋值为0；
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int p1, p2 = 0;
        for (; nums[p1]!=0 && p1<len; p1++);
        for (p2=p1; p2<len; p2++) {
            if (nums[p2] == 0) {
                continue;
            }
            nums[p1++] = nums[p2];
        }
        for (; p1<len; p1++) {
            nums[p1] = 0;
        }
    }
};