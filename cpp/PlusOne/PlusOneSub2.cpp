class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        
        for(int i=len-1; i >= 0; i--)
        {
            digits[i] +=1;
            
            if(digits[i] < 10) {
                break;
            } else {
                digits[i] %= 10;
                //digits最高位
                if(i==0) {
                    digits.insert(digits.begin(),1);
                }
            }
        }
        return digits;
    }
};