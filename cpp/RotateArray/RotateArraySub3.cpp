/* 三次翻转
 * 有几点需要注意：
 * 1. 当k>n时，取模
 * 2. 调用swap时，如果start=end，则不调用
 */
class Solution {
public:
    void swap(vector<int>& nums, int start, int end) {
        if (start==end) {
            return;
        }
        while (start<end) {
            int tmp = nums[start];
            nums[start++] = nums[end];
            nums[end--] = tmp;
        }
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k<1) {
            return;
        }
        k %= n;
        swap(nums, n-k, n-1);
        swap(nums, 0, n-k-1);
        swap(nums, 0, n-1);
    }
};