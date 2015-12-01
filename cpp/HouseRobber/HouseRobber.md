###House Robber
URL: https://leetcode.com/problems/house-robber/</br>
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it __will automatically contact the police if two adjacent houses were broken into on the same night__.</br>
Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight __without alerting the police__.

__Code:__

	#include <time.h>
	#include <stdlib.h>
	#include <iostream>
	#include <vector>
	using namespace std;    
	/*
	 * Dynamic Programming
	 *
	 * We can easy find the recurive fomular:
	 *
	 *     dp[n] = max( 
	 *                    dp[n-1],   // the previous house has been robbed. 
	 *                    dp[n-2] + money[n]  // the previous house has NOT been robbed.
	 *                )
	 *                  
	 * The initalization is obvious:
	 *     dp[1] = money[1]
	 *     dp[2] = max(money[1], money[2])
	 *
	 */
	int rob1(vector<int> &money) {

	    int n = money.size();
	    if (n==0) return 0;

	    vector<int> dp(n, 0);
	    if (n>=1) dp[0] = money[0];
	    if (n>=2) dp[1] = max(money[0], money[1]);

	    for (int i=2; i<n; i++){
	        dp[i] = max(dp[i-1], dp[i-2] + money[i]);
	    }
	    return dp[n-1];
	}
	/*
	 * Acutally, we no need to allocate an additional array for DP.
	 * we can only use several variables to record previous steps
	 */

	int rob2(vector<int> &money) {
	    int n2=0; // dp[i-2];
	    int n1=0; // dp[i-1];

	    for (int i=0; i<money.size(); i++){
	        int current = max(n1, n2 + money[i]);
	        n2 = n1;
	        n1 = current;
	    }
	    return n1;
	}

####状态压缩

这道理可以看做是状态压缩，每两个数字看做是一行，状态有3个，故需要F[N][3]的数组，F[i][j]就表示第i行状态j时rob的money。相关链接：</br>
[状态压缩一－铺地砖](http://blog.csdn.net/lu597203933/article/details/44137277)</br>
[状态压缩二－捡垃圾](http://blog.csdn.net/lu597203933/article/details/44137867)

__Code:__

	#include <iostream>
	#include <algorithm>
	#include <vector>
	using namespace std;

	#define N 10000

	class Solution {
	public:
		Solution(){
			memset(F, 0, sizeof(int)*N*3);
		}
	    int rob(vector<int> &num) {
			if(num.size() == 0) return 0;
			else if(num.size() == 1) return num[0];
			else{
				// 初始化第一行
				F[0][0] = 0;
				F[0][1] = num[1];
				F[0][2] = num[0];
				int maxMoney = max(num[1], num[0]);
				for(int i = 1; i < num.size()-1; i++){
					for(int j = 0; j < 3; j++){     
						int t = j >> 1;
						for(int k = 0; k < 3; k++){
							if( t ==  (k & (1>>0))){      // 判断第i行状态j与第i-1行各个状态是否兼容 即j的倒数第二位与k的倒数第一位是否相同
								F[i][j] = max(F[i-1][k], F[i][j]);	//  输出兼容的最大者
							}
						}
						if((j & (1<<0)) == 1) F[i][j] = F[i][j] + num[i+1];  // 如果状态j最后一位为1则 需要加上该方案数
						if(F[i][j] > maxMoney){                // 求最大的方案数
							maxMoney = F[i][j];
						}
					}
				}
				return maxMoney;
			}
	    }
	private:
		int F[N][3];
	};
