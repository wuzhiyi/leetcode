class Solution {
public:
    int numTrees(int n) {
        if (n==0) return 0;
        vector<int> nums(n+1);
        nums[0] = 1;
        for (int i=1; i<=n; i++) {
            int tmp = 0;
            for (int j=0; j<i; j++) {
                tmp += (nums[j]*nums[i-j-1]);
            }
            nums[i] = tmp;
        }
        return nums[n];
    }
};