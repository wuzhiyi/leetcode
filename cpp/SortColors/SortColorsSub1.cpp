class Solution {
private:
    void swap(int* a, int* b) {
        int tmp = *a;
        *a = *b;
        *b = tmp;
    }
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p1=0, p2=n-1;
        int i=0;
        while (i<=p2) {
            if (nums[i]==0) {
                swap(&nums[i++], &nums[p1++]);
            } else if (nums[i]==1) {
                i++;
            } else {
                swap(&nums[i], &nums[p2--]);
            }
            
        }
    }
};