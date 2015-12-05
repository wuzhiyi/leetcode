###Bitwise AND of Numbers Range
URL: https://leetcode.com/problems/bitwise-and-of-numbers-range/</br>
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.

__Code:__

	/*
	    Idea: 
	    1) we know when a number add one, some of the right bit changes from 0 to 1 or  from 1 to 0
	    2) if a bit is 0, then AND will cause this bit to 0 eventually.
	    So, we can just simply check how many left bits are same for m and n. 

	    for example: 
	        5 is 101
	        6 is 110
	        when 5 adds 1, then the right two bits are changed.  the result is 100

	        6 is 110
	        7 is 111
	        when 6 adds 1, then the right one bit is changed. the result is 110.


	         9 is 1001
	        10 is 1010
	        11 is 1011
	        12 is 1100
	        Comparing from 9 to 12, we can see the first left bit is same, that's result.
	*/
	int rangeBitwiseAnd(int m, int n) {
	    int mask = 0xffffffff;

	    /* find out the same bits in left side*/
	    while (mask != 0) {
	        if ((m & mask) == (n & mask)) {
	            break;
	        }
	        mask <<= 1;
	    }

	    return m & mask;

	}