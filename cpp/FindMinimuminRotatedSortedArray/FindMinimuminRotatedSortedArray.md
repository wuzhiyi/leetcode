###Find Minimum in Rotated Sorted Array
URL: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/</br>
Suppose a sorted array is rotated at some pivot unknown to you beforehand.</br>
(i.e., `0 1 2 4 5 6 7` might become `4 5 6 7 0 1 2`).</br>
Find the minimum element.</br>
You may assume no duplicate exists in the array.

__Code:__

	/* 
	 *  Obveriously, to search any sorted array, the binary search is the common sense.
	 * 
	 *  To solve this problem, the idea is same as the search in rotated sorted array.
	 */
	int findMin(vector<int> &num) {

	    int low=0, high=num.size()-1;

	    while(high-low>1){
	        int mid = low + (high-low)/2;
	        // Chek the array if it is non-rotated, then just return the first element.
	        if (num[low] < num[mid] && num[mid] < num[high]){
	            return num[low];
	        }

	        // The array is rotated
	        // Spli it into two part, the minimal value must be the rotated part
	        
	        // if the left part is rotated, warch the left part
	        if (num[low] > num [mid]){
	            high = mid;
	            continue;
	        }
	        // if the right part is rotated, search the right part.
	        if (num[mid] > num[high]){
	            low = mid;
	            continue;
	        }
	    }
	    // the array only has 1 element
	    if (high == low) return num[low];

	    // the array has 2 elements
	    return num[low] < num[high] ? num[low] : num[high];

	}