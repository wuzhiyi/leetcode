###Best Time to Buy and Sell Stock with Cooldown
URL: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/</br>
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

- You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
- After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)

####Example:

	prices = [1, 2, 3, 0, 2]
	maxProfit = 3
	transactions = [buy, sell, cooldown, buy, sell]

__Code:__

	class Solution {
	public:
	    int maxProfit(vector<int>& prices) {
	        int buy=INT_MIN, pre_buy=0, sell=0, pre_sell=0;
	        for (int price : prices) {
	            pre_buy = buy;
	            buy = max(pre_sell-price, pre_buy);
	            pre_sell = sell;
	            sell = max(pre_buy+price, pre_sell);
	        }
	        return sell;
	    }
	};