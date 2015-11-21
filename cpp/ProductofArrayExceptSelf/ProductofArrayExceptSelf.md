###Product of Array Except Self
URL: https://leetcode.com/problems/product-of-array-except-self/</br>
Given an array of _n_ integers where n > 1, `nums`, return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.</br>
Solve it without division and in O(_n_).</br>
For example, given `[1,2,3,4]`, return `[24,12,8,6]`.

####Follow up:
Could you solve it with constant space complexity? (Note: The output array __does not__ count as extra space for the purpose of space complexity analysis.)

__Code:__

	//解法1
	public int[] productExceptSelf(int[] nums) {
		int len = nums.length, p;
	    int[] arr = new int[nums.length];

	    arr[0] = p = 1;
	    for (int i = 1; i < len; i ++) {
	        p = p * nums[i - 1];
	        arr[i] = p;
	    }

	    p = 1;
	    for (int i = len - 2; i >= 0; i --) {
	        p = p * nums[i + 1];
	        arr[i] *= p;
	    }

	    return arr;
	}

	//解法2，递归
	public int[] productExceptSelfRev(int[] nums) {
	        multiply(nums, 1, 0, nums.length);

	        return nums;
	    }

	    private int multiply(int[] a, int fwdProduct, int indx, int N) {
	        int revProduct = 1;
	        if (indx < N) {
	            revProduct = multiply(a, fwdProduct * a[indx], indx + 1, N);
	            int cur = a[indx];
	            a[indx] = fwdProduct * revProduct;
	            revProduct *= cur;
	        }
	        return revProduct;
	    }