###H-Index II
URL: https://leetcode.com/problems/h-index-ii/</br>
Follow up for [H-Index](https://leetcode.com/problems/h-index/): What if the `citations` array is sorted in ascending order? Could you optimize your algorithm?

####Hint:

1. Expected runtime complexity is in O(log n) and the input is sorted.

__Code:__

	/* 
	 * Solutions
	 * =========
	 *
	 * At every step we need to check whether this element is not less than
	 * the remaining number of elements bigger than it(including itself) and all the values of
	 * the other elements smaller than it are not more than that number. The h_index is this
	 * number of elements bigger than it(including itself).
	 * 
	 * Time Complexity: O(N)
	 * Space Complexity: O(1)
	 * 
	 */
	class Solution {
	public:
	    int hIndex(vector<int>& citations) {
	        int h_index = 0;
	        for(int i = citations.size() - 1; i >= 0; i--)
	            if(citations[i] >= citations.size() - i && (i - 1 < 0 || citations[i - 1] <= citations.size() - i))
	                h_index = citations.size() - i;
	        return h_index;
	    }
	};