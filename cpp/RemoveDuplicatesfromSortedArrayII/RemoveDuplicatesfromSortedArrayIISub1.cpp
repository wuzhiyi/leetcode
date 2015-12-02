class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n<=2) return n;
        int pos = 0;
        int cnt = 1;
        for (int i=1; i<n; i++) {
            if (nums[i] == nums[pos]) {
                cnt++;
                if (cnt == 2) {
                    nums[++pos] = nums[i];
                }
            } else {
                nums[++pos] = nums[i];
                cnt = 1;
            }
        }
        return pos+1;
    }
};