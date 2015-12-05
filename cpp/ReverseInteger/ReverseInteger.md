###Reverse Integer
URL: https://leetcode.com/problems/reverse-integer/</br>
Reverse digits of an integer.</br>
__Example1:__ x = 123, return 321</br>
__Example2:__ x = -123, return -321</br>

####Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!</br>
If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.</br>
Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?</br>
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.</br>

####Update (2014-11-10):
Test cases had been added to test the overflow behavior.

__Code:__

	/* Why need the INT_MIN be defined like that?
	 * Please take a look: 
	 * http://stackoverflow.com/questions/14695118/2147483648-0-returns-true-in-c
	 */
	#define INT_MAX     2147483647
	#define INT_MIN     (-INT_MAX - 1)
	
	int reverse(int x) {
	    int y=0;
	    int n;
	    while( x != 0){
	        n = x%10;
	        //Checking the over/underflow.
	        //Actually, it should be y>(INT_MAX-n)/10, but n/10 is 0, so omit it.
	        if (y > INT_MAX/10 || y < INT_MIN/10){
	             return 0;
	        }
	        y = y*10 + n;
	        x /= 10;
	    }
	    return y;
	}

	#define TEST(n, e)  printf("%12d  =>  %-12d    %s!\n",  n, reverse(n),  e == reverse(n)?"passed":"failed")