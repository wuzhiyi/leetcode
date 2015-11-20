###Ugly Number
URL: https://leetcode.com/problems/ugly-number/</br>
Write a program to check whether a given number is an ugly number.</br>
Ugly numbers are positive numbers whose prime factors only include `2, 3, 5`. For example, `6, 8` are ugly while `14` is not ugly since it includes another prime factor `7`.</br>
Note that `1` is typically treated as an ugly number.

__Code:__

	class Solution {
	public:
	    //贪婪算法
	    bool isUgly(int num) {
	        if ( num == 0 ) return false;
	        //对特殊情况num=1进行判断
	        if ( num == 1 ) return true;
	        //因为2,3,5是质数，所以直接除去该因数
	        while (num % 2 == 0) num /= 2;
	        while (num % 3 == 0) num /= 3;
	        while (num % 5 == 0) num /= 5;
	        
	        return num == 1;
	    }
	};
