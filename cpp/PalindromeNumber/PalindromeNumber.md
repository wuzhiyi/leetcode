###Palindrome Number
URL: https://leetcode.com/problems/palindrome-number/</br>
Determine whether an integer is a palindrome. Do this without extra space.

####Some hints:

Could negative integers be palindromes? (ie, -1)</br>
If you are thinking of converting the integer to string, note the restriction of using extra space.</br>
You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?</br>
There is a more generic way of solving this problem.

__Code:__

	#include <stdio.h>

	class Solution {
	public:

	    bool isPalindrome(int x) {
	    	//负数不能为Palindrome No.
	        if (x<0) {
	            return false;
	        }
	        
	        int len=1;
	        //len记录x位数
	        for (len=1; (x/len) >= 10; len*=10 );
	        
	        while (x != 0 ) {
	        	//取头尾位数
	            int left = x / len;
	            int right = x % 10;
	            
	            if(left!=right){
	                return false;
	            }
	            
	            x = (x%len) / 10;
	            //len减小两位
	            len /= 100;
	        }
	        return true;
	    }
	    
	    bool isPalindrome2(int x) {
	        return (x>=0 && x == reverse(x));
	    }

	private:    
	    int reverse(int x) {
	        int y=0;

	        int n;
	        while( x!=0 ){
	            n = x%10;
	            y = y*10 + n;
	            x /= 10;
	        }
	        return y;
	    }
	};



	int main()
	{
	    Solution s;
	    printf("%d is %d\n", 0, s.isPalindrome(0) );
	    printf("%d is %d\n", -101, s.isPalindrome(-101) );
	    printf("%d is %d\n", 1001, s.isPalindrome(1001) );
	    printf("%d is %d\n", 1234321, s.isPalindrome(1234321) );
	    printf("%d is %d\n", 2147447412, s.isPalindrome(2147447412) );
	    printf("%d is %d\n", 2142, s.isPalindrome(2142) );
	}