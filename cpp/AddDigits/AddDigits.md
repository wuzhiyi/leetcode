###Add Digits
URL: https://leetcode.com/problems/add-digits/</br>
Given a non-negative integer `num`, repeatedly add all its digits until the result has only one digit.</br>
For example:</br>
Given `num = 38`, the process is like: `3 + 8 = 11`, `1 + 1 = 2`. Since `2` has only one digit, return it.</br>

####Follow up:
Could you do it without any loop/recursion in O(1) runtime?

####Hint:
1. A naive implementation of the above process is trivial. Could you come up with other methods?
2. What are all the possible results?
3. How do they occur, periodically or randomly?
4. You may find this [Wikipedia article](https://en.wikipedia.org/wiki/Digital_root) useful.

__Code:__

	class Solution {
	    public:

	        //解法1:常规法
	        int addDigits01(int num) {
	            while(num > 9) {
	                int sum;
	                for(sum=0; num > 0; sum += num%10 , num/=10);
	                num = sum;
	            }
	            return num;

	        }

	        //This solution looks is very tricky, but acutally it is easy to understand.
	        //it just keep adding the last digital until the num < 10
	        int addDigits02(int num) {
	            while(num > 9) {
	                num = num / 10 + num % 10;
	            }
	            return num;

	        }

	        // Let's observe the pattern
	        //    1    1
	        //    2    2
	        //    ... ...
	        //    8    8    
	        //    9    9    
	        //    10    1
	        //    11    2
	        //    12    3    
	        //    ... ...
	        //    17    8
	        //    18    9
	        //    19    1
	        //    20    2
	        //    ...  ...
	        // It looks most of number just simply %9 is the answer, 
	        // but there are some edge cases.
	        //    9%9=0 but we need 9. 
	        //    18%9=0 but we need 9
	        // so we can find the solution is:
	        //    1) num <=9, return num
	        //    2) num > 9, reutrn num%9 if num%9>0
	        //                return 9 if num%9 ==0
	        int addDigits03(int num) {
	            return num >9 ? ((num %9)==0 ? 9:num%9) : num;
	        }

	        //But actually, we can use (num-1)%9 + 1 to make all cases right.
	        int addDigits04(int num){
	            return (num - 1) % 9 + 1;
	        }

	        //This solution is similar with pervious solution.
	        int addDigits05(int num){
	            return num - 9 * ((num - 1)/9);
	        }

	};