###Find Peak Element
URL: https://leetcode.com/problems/find-peak-element/</br>
A peak element is an element that is greater than its neighbors.</br>
Given an input array where `num[i] ≠ num[i+1]`, find a peak element and return its index.</br>
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.</br>
You may imagine that `num[-1] = num[n] = -∞`.</br>
For example, in array `[1, 2, 3, 1]`, 3 is a peak element and your function should return the index number 2.</br>

####Note:
Your solution should be in logarithmic complexity.

__Code:__

	/*
	 *    Binary search is common idea here.
	 *
	 *    However, you need to think about two senarios:
	 *
	 *    1) Becasue we need check `num[mid-1]`, `num[mid]`, `num[mid+1]`, 
	 *       So, we need make sure there hasn't out-of-boundary issue.
	 *   
	 *
	 *
	 *    2) There are multiple Peak elements.
	 *
	 *       For example: [1,2,1,2,1], or [ 1,2,3,1,2,1]
	 *
	 *       LeetCode doesn't tell you what the expected result is. I guess:
	 *
	 *       2.1) for [1,2,1,2,1] you can return either 1 or 3, because both them are peak elements
	 *
	 *       2.1) for [1,2,3,2,4,2,1] it should return 4, because num[4] is the real peak.  but Leetcode accept either 2 or 4
	 *
	 */

	int findPeakElement(const vector<int> &num) {

	    int n = num.size();
	    int low = 0;
	    int high = n - 1;

	    int mid = 0, v1, v2;

	    while ( low < high ) {

	        // Find the index of middle element
	        mid = low + ( high - low ) / 2;

	        // Compare middle element with its neighbours (if neighbours exist)
	        if ( ( mid == 0 || num[mid] > num[mid-1] ) && 
	                ( mid == n-1 ||  num[mid] > num[mid+1] )  ){
	            return mid;
	        }

	        // If middle element is not peak and its left neighbor is greater than it
	        // then left half must have a peak element
	        if (mid >0 && num[mid-1] > num[mid]){
	            high = mid - 1;
	        // If middle element is not peak and its right neighbor is greater than it
	        // then right half must have a peak element
	        }else{
	            low = mid + 1;
	        }

	    }

	    return low;
	}
