/* 每次循环新建一个vector，为第i行
 * 然后将v添加到pascalTriangle
 * 测试中能通过，但是submission不通过
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i=0; i<numRows; i++) {
            vector<int> v;
            if (i==0) {
                v.push_back(1);
            } else {
                v.push_back(1) ;
                for (int j=0; j<pascalTriangle[i-1].size(); j++) {
                    v.push_back(ret[i-1][j] + ret[i-1][j+1]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};