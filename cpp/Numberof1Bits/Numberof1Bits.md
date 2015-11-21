###Number of 1 Bits
URL: https://leetcode.com/problems/number-of-1-bits/</br>
Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the [Hamming weight](https://en.wikipedia.org/wiki/Hamming_weight)).</br>
For example, the 32-bit integer ’11' has binary representation `00000000000000000000000000001011`, so the function should return 3.

__Code:__

	class Solution {
	public:
	    int hammingWeight(uint32_t n) {		//1
	        int cnt = 0;
	        for(;n>0; n/=2){
	            if (n & 0x1) cnt++;			//2
	        }
	        return cnt;
	    }
	};

###1 uint32_t

Fixed width integer types (since C++11). Unsigned integer type with width of exactly 32 bits. (provided only if the implementation directly supports the type) 

###2 0x

C++ 语言中以 0x 开头接 0~9 和 a~f (同A~F) 表示的数为十六进制数.