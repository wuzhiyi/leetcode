/* 直接对所有元素二分法查找
 * 定位时取商为行数，取余为列数
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if (n==0) return false;
        int m = matrix[0].size();
        if (m==0) return false;
        
        int start=0, end=n*m-1;
        while(start+1<end) {
            int mid = start + (end-start)/2;
            int row = mid/m;
            int col = mid%m;
            if (matrix[row][col]<target) {
                start=mid;
            } else {
                end=mid;
            }
        }
        if (matrix[start/m][start%m]==target || matrix[end/m][end%m]==target) return true;
        return false;
    }
};