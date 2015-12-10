class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = INT_MIN;
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            sum += nums[i];
            result = max(sum, result);
            if (sum<0) {
                sum = 0;
            }
        }
        return result;
    }
};