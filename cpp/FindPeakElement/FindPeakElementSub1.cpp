/* 只找出第一个比相邻元素大的元素，并返回index
 */

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n==0) return -1;
        if (n==1) return 0;
        for (int i=0; i<n; i++) {
            if (i==0 && nums[i]>nums[i+1]) {
                return i;
            }
            if (i==n-1 && nums[i]>nums[i-1]) {
                return i;
            }
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]) {
                return i;
            }
        }
        return -1;
    }
};