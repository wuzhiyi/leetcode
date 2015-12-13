/* recursive
 */

class Solution {
private:
    void permuteHelper(vector<vector<int>>& vv, vector<int>& v, vector<int>& nums) {
        if (v.size()==nums.size()) {
            vv.push_back(v);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (find(v.begin(), v.end(), nums[i]) != v.end()) continue;
            v.push_back(nums[i]);
            permuteHelper(vv, v, nums);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vv;
        vector<int> v;
        if (nums.size()==0) return vv;
        permuteHelper(vv, v, nums);
        return vv;
    }
};