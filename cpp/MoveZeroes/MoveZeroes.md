###Move Zeroes
URL: https://leetcode.com/problems/move-zeroes/</br>
Given an array `nums`, write a function to move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.</br>
For example, given `nums = [0, 1, 0, 3, 12]`, after calling your function, `nums` should be `[1, 3, 12, 0, 0]`.

Note:
You must do this __in-place__ without making a copy of the array.
Minimize the total number of operations.

__Code:__

	class Solution {
	public:
		//解法1:将非0元素往前挪，然后再给数组赋值相应个数的0元素
	    void moveZeroes(vector<int>& nums) {
	        int i = 0, poz = 0;
	        //poz指针将非0元素依次赋值给i，结束条件为poz指针已跳出数组
	        for(i = 0; i < nums.size() && poz < nums.size(); i++) {
	                while(nums[poz] == 0)
	                    poz++;
	                if(poz < nums.size())
	                    nums[i] = nums[poz];
	                else
	                    i--;
	                poz++;
	        }
	        //将剩下的元素全部赋值为0
	        for(; i < nums.size(); i++)
	            nums[i] = 0;
	    }

	    //解法2: p1指针指向非0数组的尾巴，p2指针是剩下数组的头
	    void moveZeroes(vector<int>& nums) {
	        int p1=0, p2=0;
	        //p1指针找到第一个0
	        for (; nums[p1]!=0 && p1<nums.size(); p1++);
	        //p2指针找到不为0的元素，然后赋值给p1
	        for (p2=p1; p2<nums.size(); p2++) {
	            if ( nums[p2] == 0 ) continue;
	            nums[p1++] = nums[p2]; 
	        }    
	        while ( p1<nums.size() ) nums[p1++] = 0;
	    }

	};