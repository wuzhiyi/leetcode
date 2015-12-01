###Single Number II
URL: https://leetcode.com/problems/single-number-ii/</br>
Given an array of integers, every element appears _three_ times except for one. Find that single one.</br>
####Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

####解法1

int 数据共有32位，可以用32变量存储这 N 个元素中各个二进制位上 1 出现的次数，最后在进行模三 操作，如果为 1，那说明这一位是要找元素二进制表示中为 1 的那一位。

__Code:__

	class Solution {
	public:
	    int singleNumber(int A[], int n) {
	        int bitnum[32]={0};
	        int res=0;
	        for(int i=0; i<32; i++){
	            for(int j=0; j<n; j++){
	                bitnum[i]+=(A[j]>>i)&1;
	            }
	            res|=(bitnum[i]%3)<<i;
	        }
	        return res;
	    }
	};

####解法2

利用三个变量分别保存各个二进制位上 1 出现一次、两次、三次的分布情况，最后只需返回变量一就行了。</br>
__解释：__每次循环先计算 twos，即出现两次的 1 的分布，然后计算出现一次的 1 的分布，接着 二者进行与操作得到出现三次的 1 的分布情况，然后对 threes 取反，再与 ones、twos进行与操作，这样的目的是将出现了三次的位置清零。
        这个方法虽然更快、更省空间了，但是并不通用。

__Code:__

	class Solution {
	public:
	    int singleNumber(int A[], int n) {
	        int one=0, two=0, three=0;
	        for(int i=0; i<n; i++){
	            two |= one&A[i];
	            one^=A[i];
	            //cout<<one<<endl;
	            three=one&two;
	            one&= ~three;
	            two&= ~three;
	        }
	        return one;
	    }
	};