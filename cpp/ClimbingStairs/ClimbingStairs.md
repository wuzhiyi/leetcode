###Climbing Stairs
URL: https://leetcode.com/problems/climbing-stairs/</br>
You are climbing a stair case. It takes _n_ steps to reach to the top.</br>
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

__Code:__

	class Solution {
	public:
	    
	    int climbStairs1(int n) {
	       if (n<=3) return n;
	       int a[2]={2,3};
	       for(int i=4; i<=n; i++){
	           int t = a[0] + a[1];
	           a[0] = a[1];
	           a[1] = t;
	       }
	       return a[1];
	    }
	    
	    int climbStairs2(int n) {
	        if (n<=3) return n;
	        return climbStairs(n-1) + climbStairs(n-2);
	    }
	};