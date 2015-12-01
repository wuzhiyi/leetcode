class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int tmp = -1;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] != tmp + 1) {
                return nums[i]-1;
            }
            tmp = nums[i];
        }
    }
};