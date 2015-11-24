/* 就sub1稍微改动，AC
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0){
            return vector<vector<int>> (0);
        }
        
        vector<vector<int>> ret;
        for (int i=0;i<numRows; i++) {
            vector<int> v;
            for (int j=0; j<i+1; j++) {
                if (j==0 || j==i) {
                    v.push_back(1);
                } else {
                    v.push_back(ret[i-1][j-1]+ret[i-1][j]);
                }
            }
            ret.push_back(v);
        }
        return ret;
    }
};