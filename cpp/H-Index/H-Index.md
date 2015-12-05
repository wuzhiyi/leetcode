###H-Index
URL: https://leetcode.com/problems/h-index/</br>
Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given `citations = [3, 0, 6, 1, 5]`, which means the researcher has 5 papers in total and each of them had received `3, 0, 6, 1, 5` citations respectively. Since the researcher has `3` papers with at least `3` citations each and the remaining two with no more than `3` citations each, his h-index is `3`.

Note: If there are several possible values for `h`, the maximum one is taken as the h-index.

####Hint:

1. An easy approach is to sort the array first.
2. What are the possible values of h-index?
3. A faster approach is to use extra space.

__Code:__

	/* 
	 * Solutions
	 * =========
	 *
	 * A simple solution would be to sort the vector and then run through it starting with
	 * the last element. At every step we need to check whether this element is not less than
	 * the remaining number of elements bigger than it(including itself) and all the values of
	 * the other elements smaller than it are not more than that number. The h_index is this
	 * number of elements bigger than it(including itself).
	 * 
	 * Time Complexity: O(N log N)
	 * Space Complexity: O(1)
	 * 
	 */
	#include <algorithm>
	class Solution {
	public:
	    int hIndex(vector<int>& citations) {
	        sort(citations.begin(), citations.end());
	        int h_index = 0;
	        for(int i = citations.size() - 1; i >= 0; i--)
	            if(citations[i] >= citations.size() - i && (i - 1 < 0 || citations[i - 1] <= citations.size() - i))
	                h_index = citations.size() - i;
	        return h_index;
	    }
	};
