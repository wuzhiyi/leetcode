/* 先按行查找，再按列查找
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size()==0) return false;
        int m = matrix.size()-1;
        int n = matrix[0].size()-1;
        int mlow=0, mhigh=m;
        while (mlow <= mhigh) {
            int mmid = mlow + (mhigh-mlow)/2;
            if (matrix[mmid][0]==target) return true;
            if (matrix[mmid][0]>target) {
                mhigh = mmid-1;
                continue;
            }
            if (matrix[mmid][0]<target) {
                mlow = mmid+1;
                continue;
            }
        }
        if (mlow-1<0) {
            return false;
        } else {
            m = mlow-1;
        }
        int nlow=0, nhigh=n;
        cout << m << endl;
        while (nlow <= nhigh) {
            int nmid = nlow + (nhigh-nlow)/2;
            if (matrix[m][nmid]==target) return true;
            if (matrix[m][nmid]>target) {
                nhigh = nmid-1;
                continue;
            }
            if (matrix[m][nmid]<target) {
                nlow = nmid+1;
                continue;
            }
        }
        return false;
    }
};