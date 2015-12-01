###Single Number III
URL: https://leetcode.com/problems/single-number-iii/</br>
Given an array of numbers `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.</br>
For example:</br>
Given `nums = [1, 2, 1, 3, 2, 5]`, return `[3, 5]`.
####Note:
1. The order of the result is not important. So in the above example, `[5, 3]` is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

__Analysis:__
两个相等的数异或结果为 0。因此，首次扫描数组，得到两个单独的数 A、B 的异或结果 AxorB。因为 A 和 B 不相等，因此 AxorB 一定不为 0，且二进制位为 1 的位 A 和 B 一定不同。任取 AxorB 中的一个二进制位，可以将原数组元素分成两组异或即得结果。

注意 `n&(~(n-1))` 表示取的n中的最后一位二进制位。

__Code:__

	class Solution {
	public:
	    vector<int> singleNumber(vector<int>& nums) {
	        int len = nums.size();
	        int AxorB = 0;
	        for(int i=0; i<len; i++){
	            AxorB ^= nums[i];
	        }
	        int mask = AxorB & (~(AxorB-1));
	        int A = 0;
	        int B = 0;
	        for(int i=0; i<len; i++){
	            if((mask&nums[i])==0){
	                A ^= nums[i];
	            }else{
	                B ^= nums[i];
	            }
	        }
	        return vector<int>({A, B});
	    }
	};