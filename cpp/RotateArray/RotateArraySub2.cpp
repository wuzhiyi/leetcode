/* Time Limit Exceeded
 * 在sub1的基础上改进，但还是超时
 * 只要是有右移位的操作，基本上当数组很大时就一定会超时
 */
 
class Solution {
public:
    void swap(vector<int>& nums, int a, int b) {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
    
    void right(vector<int>& nums, int begin, int end) {
        int tmp = nums[end];
        for (int x=end; x>begin; x--) {
            nums[x] = nums[x-1];
        }
        nums[begin] = tmp;
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size()-1;
        if(k<0 || k>n) {
            return;
        }
        for (int i=0; i<k; i++) {
            swap(nums, i, n-k+i+1);
        }
        for (int j=0; j<k; j++) {
            right(nums, k, n);
        }
    }
};