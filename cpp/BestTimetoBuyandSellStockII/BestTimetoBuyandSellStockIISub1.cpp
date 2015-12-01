class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0, begin=0, end=0;
        bool up=false, down=false;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i]>prices[i-1] && up==false) {
                begin = i-1;
                up = true;
                down = false;
                
            }
            if (prices[i]<prices[i-1] && down==false) {
                end = i-1;
                up = false;
                down = true;
                max += (prices[end] - prices[begin]);
            }
        }
        if (begin<prices.size() && up==true) {
            max += (prices[prices.size()-1] - prices[begin]);
        }
        return max;
    }
};