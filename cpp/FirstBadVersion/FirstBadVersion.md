###First Bad Version
URL: https://leetcode.com/problems/first-bad-version/</br>
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.</br>
Suppose you have `n` versions `[1, 2, ..., n]` and you want to find out the first bad one, which causes all the following ones to be bad.</br>
You are given an API `bool isBadVersion(version)` which will return whether `version` is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

__Code:__

	// Forward declaration of isBadVersion API.
	bool isBadVersion(int version);

	class Solution {
	public:
	    //二分查找
	    int firstBadVersion(int n) {
	    	//头尾标记
	        int low=1, high=n;
	        while(low <= high) {
	        	//二分
	            int mid = low + (high - low)/2;
	            if (isBadVersion(mid) && !isBadVersion(mid-1)){
	                return mid;
	            }
	            if (isBadVersion(mid)) {
	                high = mid - 1;
	            }else{
	                low = mid + 1;
	            }
	        }
	        return -1;
	    }
	};
