class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ret;
        while (digits.size()>0) {
            int x = digits.back();
            digits.pop_back();
            x += carry;
            ret.insert(ret.begin(), x%10);
            carry = x/10;
        }
        if (carry>0) {
            ret.insert(ret.begin(), carry);
        }
        return ret;
    }
    
};