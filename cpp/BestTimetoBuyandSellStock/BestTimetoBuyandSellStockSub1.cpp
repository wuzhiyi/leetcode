class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int begin=0, end=0, max=0, delta=0;
        for (int i=0; i<prices.size(); i++) {
            end = i;
            delta = prices[end] - prices[begin];
            if (delta <= 0) {
                begin = i;
            }
            if (delta > max) {
                max = delta;
            }
        }
        return max;
    }
};