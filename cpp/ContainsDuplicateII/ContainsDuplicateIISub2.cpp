/* map映射
 * 初始化一个空map，<nums[i], i>
 * map中两个int，第一个映射nums[i],第二个映射下标i
 * 每次循环，查找map是否存在nums值且其下标差小于k，有，则返回true
 * 无，则将该下标映射到map上
 */

class Solution {
	public:
	    bool containsNearbyDuplicate(vector<int>& nums, int k) {
	        unordered_map<int, int> m;
	        for (int i=0; i<nums.size(); i++) {
	            int n = nums[i];
	            if (m.find(n) != m.end() && i - m[n] <= k) {
	                return true;
	            }
	            m[n] = i;
	        }
	        return false;
	    }
	};