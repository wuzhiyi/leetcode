/* loop
 */

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vv;
        vv.push_back(nums);
        if (nums.size()<2) return vv;
        //permute基准点pos
        int pos=0;
        while (pos<nums.size()-1) {
            int size = vv.size();
            for (int i=0; i<size; i++) {
                for (int j=pos+1; j<vv[i].size(); j++) {
                    vector<int> v = vv[i];
                    int tmp = v[j];
                    v[j] = v[pos];
                    v[pos] = tmp;
                    vv.push_back(v);
                }
            }
            pos++;
        }
        return vv;
    }
};