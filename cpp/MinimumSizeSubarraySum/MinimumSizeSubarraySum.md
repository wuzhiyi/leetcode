###Minimum Size Subarray Sum
URL: https://leetcode.com/problems/minimum-size-subarray-sum/</br>
Given an array of __n__ positive integers and a positive integer __s__, find the minimal length of a subarray of which the sum ≥ __s__. If there isn't one, return 0 instead.</br>
For example, given the array `[2,3,1,2,4,3]` and `s = 7`,</br>
the subarray `[4,3]` has the minimal length under the problem constraint.

####More practice:
If you have figured out the O(_n_) solution, try coding another solution of which the time complexity is O(_n_ log n).

__Code:__


	class Solution {
	public:
	    int minSubArrayLen(int s, vector<int>& nums) {
	        int min = nums.size();
	        int begin=0, end=0;
	        int sum = 0;
	        bool has = false;
	        
	        for (int i=0; i<nums.size(); i++, end++){
	            
	            sum += nums[i];
	            
	            while (sum >= s && begin <= end) {
	                //the 1 is minial length, just return
	                if (begin == end) return 1;
	                
	                if (end-begin+1 < min) {
	                    min = end - begin + 1;
	                    has = true;
	                }
	                //move the begin
	                sum -= nums[begin++];
	            }
	 
	        }
	        
	        return has ? min : 0; 
	    }
	};