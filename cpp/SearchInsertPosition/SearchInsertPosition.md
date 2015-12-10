###Search Insert Position
URL: https://leetcode.com/problems/search-insert-position/</br>
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.</br>
You may assume no duplicates in the array.</br>
Here are few examples.</br>
`[1,3,5,6]`, 5 → 2</br>
`[1,3,5,6]`, 2 → 1</br>
`[1,3,5,6]`, 7 → 4</br>
`[1,3,5,6]`, 0 → 0

__Code:__

	int binary_search(int A[], int n, int key) {
	    int low = 0;
	    int high = n-1;
	    while (low <= high){
	        int mid = low +(high-low)/2;
	        if (A[mid] == key){
	            return mid;
	        }
	        if ( key> A[mid] ) {
	            low = mid+1;
	        }else{
	            high = mid-1;
	        }
	    }
	    return low;
	}
	int searchInsert(int A[], int n, int target) {
	    if (n==0) return n;
	    return binary_search(A, n, target);
	}
