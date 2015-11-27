class Solution {
private:
    int getSquaresSum(int n) {
        int sum = 0;
        while (n>0) {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        while (getSquaresSum(n) > 9) {
            n = getSquaresSum(n);
        }
        //注意搂底
        n = getSquaresSum(n);
        return n == 1;
    }
};