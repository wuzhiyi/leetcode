/* 左右双指针
 * O(n)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int ret = INT_MIN;
        while (left<right) {
            int area = 0;
            if (height[left]>height[right]) {
                area = height[right]*(right-left);
                right--;
            } else {
                area = height[left]*(right-left);
                left++;
            }
            if (ret<area) ret = area;
        }
        return ret;
    }
};