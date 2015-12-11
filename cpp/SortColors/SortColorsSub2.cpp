class Solution {
private:
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p1=0, p2=n-1;
        for (int i=0; i<=p2; i++) {
            if (nums[i]==0) swap(nums, p1++, i);
            if (nums[i]==2) swap(nums, p2--, i--);
        }
    }
};