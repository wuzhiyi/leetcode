/* Runtime: N/A
 */

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(1,1);
        while(v.size()<n) {
            int next = min(v.back()*2, v.back()*3, v.back()*5);
            v.push_back(next);
        }
        return v.back();
    }
};