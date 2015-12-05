/* 迭代版
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result(1);
        for (int i=0; i<nums.size(); ++i) {
            int length = result.size();
            for (int j=0; j<length; ++j) {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }
        return result;
    }
};