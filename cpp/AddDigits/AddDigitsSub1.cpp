//Exceed Time Limit
#include <iostream>
using namespace std;

class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n>10) {
            sum += n%10;
            n /= 10;
        }
        sum += n%10;
        
        return sum;
    }
    
    int addDigits(int num) {
        int ret = num;
        if(ret < 10) {
            return ret;
        }
        
        while (ret>10) {
            ret = getSum(ret);
        }
        return ret;
    }
};

int main()
{
    Solution s;
    int num = 889;
    
    cout << "addDigits(" << num << ") = " << s.addDigits(num) << endl;
    
    return 0;
}