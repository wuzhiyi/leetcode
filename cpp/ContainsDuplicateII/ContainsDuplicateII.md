###Contains Duplicate II
URL: https://leetcode.com/problems/contains-duplicate-ii/</br>
Given an array of integers and an integer _k_, find out whether there are two distinct indices _i_ and _j_ in the array such that __nums[i] = nums[j]__ and the difference between _i_ and _j_ is at most _k_.

__Code:__

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