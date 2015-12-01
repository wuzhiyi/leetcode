class Solution {
public:
    int rob(vector<int>& nums) {
        int n0=0;
        int n1=0;
        for (int i=0; i<nums.size(); i++) {
            int tmp = n0;
            n0 = max(n0, n1);
            n1 = tmp + nums[i];
        }
        return max(n0, n1);
    }
};