/* 有几个注意点：
 * 1. 判断条件i<(n+1)/2;
 * 2. 判断条件j<n-i;
 * 3. 注意rotate方向
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        for (int i=0; i<(n+1)/2; i++) {
            for (int j=i; j<n-i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = tmp;
            }
        }
    }
};