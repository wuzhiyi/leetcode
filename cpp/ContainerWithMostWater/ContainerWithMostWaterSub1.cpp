/* Time limit exceeded
 * traditional way, O(n^2)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ret = INT_MIN;
        for (int i=0; i<height.size(); i++) {
            for (int j=0; j<height.size(); j++) {
                int tmp = (j-i)*min(height[i], height[j]);
                if (ret<tmp) ret = tmp;
            }
        }
        return ret;
    }
};