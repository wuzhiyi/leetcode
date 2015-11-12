###26 Remove Duplicates from Sorted Array
URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array/</br>
Given a sorted array, remove the duplicates in place such that each element appear only _once_ and return the new length.</br>
Do not allocate extra space for another array, you must do this in place with constant memory.</br>
For example,</br>
Given input array _nums_ = `[1,1,2]`,</br>
Your function should return length = `2`, with the first two elements of _nums_ being `1` and `2` respectively. It doesn't matter what you leave beyond the new length.</br>

__Code:__

	class Solution {
	public:
	    int removeDuplicates(int A[], int n) {
	        //数组长度小于2，返回n
	        if (n<=1) return n;
	        
	        int pos=0;
	        for(int i=0; i<n-1; i++) {
	        	//如果跳蛋不等于右一位, pos=右一位元素
	            if (A[i] != A[i+1]) {
	                A[++pos] = A[i+1];
	            }
	        }
	        return pos+1;
	    }
	};

