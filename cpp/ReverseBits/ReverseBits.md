###Reverse Bits
URL: https://leetcode.com/problems/reverse-bits/</br>
Reverse bits of a given 32 bits unsigned integer.</br>
For example, given input 43261596 (represented in binary as __00000010100101000001111010011100__), return 964176192 (represented in binary as __00111001011110000010100101000000__).

####Follow up:
If this function is called many times, how would you optimize it?</br>
Related problem: [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

__Code:__

	class Solution {
	public:
	    uint32_t reverseBits(uint32_t n) {
	        uint32_t ret=0;
	        for(int i=0; i<32; i++) {
	            ret = (ret*2) + (n & 0x1);
	            n /=2 ;
	        }
	        return ret;
	    }
	};