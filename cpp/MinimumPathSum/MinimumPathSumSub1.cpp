/* grid[i][j]代表从起点到该点的最小sum
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.size()<=0) return 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                //Boundary Condition
                int top = i-1<0 ? INT_MAX : grid[i-1][j];
                int left = j-1<0 ? INT_MAX : grid[i][j-1];
                if (top==INT_MAX && left==INT_MAX) continue;
                grid[i][j] += min(top, left);
            }
        }
        return grid[m-1][n-1];
    }
};