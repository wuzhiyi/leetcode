###88 Merge Sorted Array
URL: https://leetcode.com/problems/merge-sorted-array/</br>
Given two sorted integer arrays _nums1_ and _nums2_, merge _nums2_ into _nums1_ as one sorted array.</br>
__Note:__</br>
You may assume that _nums1_ has enough space (size that is greater or equal to _m_ + _n_) to hold additional elements from _nums2_. The number of elements initialized in _nums1_ and _nums2_ are _m_ and _n_ respectively.

__Code:__

	class Solution {
	public:
		//将nums1扩充为m+n,然后从尾巴开始，选择nums1和nums2中较大值赋值
	    void merge(int A[], int m, int B[], int n) {
	        int i = m - 1;
	        int j = n - 1;
	        int k = m + n - 1;
	        // when B is all merged into A, job done
	        while (j >= 0) {
	            // merge
	            if (i < 0 || B[j] > A[i]) {
	                // when A is done or A is less than B, choose B
	                A[k] = B[j];
	                j--;
	            } else {
	                A[k] = A[i];
	                i--;
	            }
	            k--;
	        }         
	    }
	 
	 };