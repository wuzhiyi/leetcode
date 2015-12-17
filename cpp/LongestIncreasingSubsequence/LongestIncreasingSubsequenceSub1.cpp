class Solution {
private:
    vector <int> v;
public:
    int lengthOfLIS(vector<int>& nums) {
        int ret = 0;
        if(nums.size()) {
            v.push_back(1);
            ret = 1;
            for(int i=1; i<nums.size(); i++) {
                int tmp = 1;
                for(int j=0; j<v.size(); j++) {
                    if(nums[i]>nums[j])
                        tmp = max(tmp, v[j]+1);
                }
                v.push_back(tmp);
                ret = max(tmp, ret);
            }
        }
        return ret;
    }
    
};