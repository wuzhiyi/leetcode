class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.size();
        int blen = b.size();
        bool carry = false;
        string result;
        while (alen>0 || blen>0) {
            int abit = alen<=0 ? 0 : a[alen-1]-'0';
            int bbit = blen<=0 ? 0 : b[blen-1]-'0';
            int cbit = carry ? 1 : 0;
            result.insert(result.begin(), '0'+((abit+bbit+cbit)&1));
            carry = (abit+bbit+cbit)>1;
            alen--, blen--;
        }
        if (carry) {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};