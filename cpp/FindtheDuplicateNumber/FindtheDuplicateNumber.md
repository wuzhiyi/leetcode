###Find the Duplicate Number
URL: https://leetcode.com/problems/find-the-duplicate-number/</br>
Given an array _nums_ containing _n_ + 1 integers where each integer is between 1 and _n_ (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.</br>

####Note:
1. You __must not__ modify the array (assume the array is read only).
2. You must use only constant, O(1) extra space.
3. Your runtime complexity should be less than `O(n2)`.
4. There is only one duplicate number in the array, but it could be repeated more than once.

__Code:__

	class Solution {
	public:
	    //
	    // This problem can be transfromed to "Linked List Cycle" problem.
	    // There are two pointers, one goes one step, another goes two steps.
	    //
	    // Refer to: https://en.wikipedia.org/wiki/Cycle_detection
	    //
	    int findDuplicate(vector<int>& nums) {
	        int n = nums.size();
	        int one = n;
	        int two = n;

	       do{
	            one = nums[one-1];
	            two = nums[nums[two-1]-1];
	        } while(one != two); 
	        
	        //find the start point of the cycle
	        one = n;
	        while(one != two){
	            one = nums[one-1];
	            two = nums[two-1];
	        }
	        
	        return one;
	    }
	};