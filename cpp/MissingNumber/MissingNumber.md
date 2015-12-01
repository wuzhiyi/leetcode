###Missing Number
URL: https://leetcode.com/problems/missing-number/</br>
Given an array containing _n_ distinct numbers taken from `0, 1, 2, ..., n`, find the one that is missing from the array.

For example,
Given _nums_ = `[0, 1, 3]` return `2`.

####Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

####二分搜索法 Binary Search

复杂度

时间 O(NlogN) 空间 O(1)

思路

先将数组排序，然后进行二分搜索。显然，中点的下标和中点的值相同时，说明从起始到中点没有错位，缺失数应该在数组后边。如果不相等，说明前面已经有错位，缺失数在左边。如果缺失数是最后一个的话，那整个数组都没有错位，则要返回最后一个加1。

注意

虽然原题中这个方法并不是最优的，但如果题目中的数组已经排序的了，那二分法就比其他两个方法要好了。

代码

	public class Solution {
	    public int missingNumber(int[] nums) {
	        Arrays.sort(nums);
	        int min = 0, max = nums.length - 1;
	        while(min < max){
	            int mid = (min + max) / 2;
	            // 没错位，在右边。有错位，则在左边
	            if(mid == nums[mid]){
	                min = mid + 1;
	            } else {
	                max = mid - 1;
	            }
	        }
	        // 如果没有错位，则返回最后一个数加1
	        return nums[min] == min ? min + 1 : min;
	    }
	}

####等差数列计算法 Arithmetic Progression

复杂度

时间 O(N) 空间 O(1)

思路

由题意，大小为n的数组里的所有数都是0 - n之间的数，作为等差数列，如果没有缺失的时候它的和是能O(1)计算出来的，所以我们遍历一遍记录最大、最小和数组和，用期望数组和减去实际数组和，就是缺失的整数

注意

缺失0和缺失n的时候要特殊处理，因为他们俩的期望和减去实际和都是0。记录最小值可以用来判断是否缺失0。

代码

	public class Solution {
	    public int missingNumber(int[] nums) {
	        if(nums.length == 0) return 0;
	        int max =0, min= nums[0], sum = 0;
	        for(int i = 0; i < nums.length; i++){
	            sum += nums[i];
	            max = Math.max(max, nums[i]);
	            min = Math.min(min, nums[i]);
	        }
	        int correctSum = (max + 0) * (max - 0 + 1) / 2;
	        return correctSum - sum;
	    }
	}

####异或法 Exclusive OR

复杂度

时间 O(N) 空间 O(1)

思路

根据异或的特性，对于一个数，异或自己是0，异或0是自己，所以我们把0-n都异或一遍，再对着给定数组异或一遍，结果就是缺失的数。

代码

	public class Solution {
	    public int missingNumber(int[] nums) {
	        int res = 0;
	        for(int i = 0; i <= nums.length; i++){
	            res ^= i == nums.length ? i : i ^ nums[i];
	        }
	        return res;
	    }
	}
First Missing Positive

Given an unsorted integer array, find the first missing positive integer.

For example, Given [1,2,0] return 3, and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

####映射法

复杂度

时间 O(N) 空间 O(1)

思路

核心思想就是遍历数组时，将每个元素，和以该元素为下标的元素进行置换，比如第一个元素是3，就将它置换到下标为3的地方，而原本下标为3的地方的元素就换到第一个来。如果换来的元素也是在正确的位置就检查下一个元素，否则继续交换，直到：

待交换的两个数是一样的
当前位置的元素没有对应的目的地（比如负数，或者超界元素）
注意

数组是从0开始的，而正数是从1开始的，为了简化映射关系，把数组里所有元素都减了1，最后返回答案时再加1即可。
如果最后还没找到，就说明缺失的是最后一个数n
代码

	public class Solution {
	    public int firstMissingPositive(int[] nums) {
	        //减1预处理数组，简化映射关系
	        for(int i = 0; i < nums.length; i++){
	            nums[i]--;
	        }
	        for(int i = 0; i < nums.length;i++){
	            while(nums[i]!=i && nums[i] >=0 && nums[i]<nums.length && nums[i]!=nums[nums[i]]){
	                int tmp = nums[i];
	                nums[i] = nums[nums[i]];
	                nums[tmp] = tmp; 
	            }
	        }
	        //找出第一个不在对应位置的数
	        for(int i = 0; i < nums.length; i++){
	            if(nums[i]!=i) return i+1;
	        }
	        //都没找到说明是最后一个数
	        return nums.length+1;
	    }
	}

__Code:__

	class Solution {
	public:
	    // This problem can be converted to the classic problem --
	    //    `There is an array, all of numbers except one appears twice, and that one only appears once`
	    // It means, we can combin two arrays together, one is [1..n], another one is `nums`.
	    // Then, you know, we can use the XOR solve this problem.
	    
	    int missingNumber01(vector<int>& nums) {
	        int result = 0;
	        for(int i=0; i<nums.size(); i++){
	            result ^=  nums[i];
	        }
	        for(int i=1; i<=nums.size(); i++){
	            result ^=(i);
	        }
	        return result;
	    }
	    
	    // We can simplify the previous solution as below
	    int missingNumber02(vector<int>& nums) {
	        int result = 0;
	        for(int i=0; i<nums.size(); i++){
	            result = result ^ (i+1) ^ nums[i];
	        }
	        return result;
	    }
	};