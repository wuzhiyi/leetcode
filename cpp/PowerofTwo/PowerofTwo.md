###Power of Two
URL: https://leetcode.com/problems/power-of-two/</br>
Given an integer, write a function to determine if it is a power of two.

__Code:__

	class Solution {
	public:

	    //2次方二进制都为:1000...
	    bool isPowerOfTwo1(int n) {
	        int cnt = 0; //num of bits 1
	        for(; n>0; n>>=1){
	        	//找到1
	            if ( n & 1 ) {
	                cnt++;
	                if (cnt>1) return false;
	            }
	        }
	        return cnt==1;
	    }
	    
	    //we notice: (2^n-1) always be 1111111...
	    //so, (2^n) & (2^n-1) always be zero
	    bool isPowerOfTwo2(int n) {
	        return n<=0 ? false : (n & (n-1)) == 0;
	    }
	};