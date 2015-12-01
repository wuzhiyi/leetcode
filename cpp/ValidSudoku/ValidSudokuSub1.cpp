/* 分别建立row,col,blk的映射
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int cnt=9;
        bool row_map[cnt][cnt]={false};
        bool col_map[cnt][cnt]={false};
        bool blk_map[cnt][cnt]={false};
        for (int r=0; r<board.size(); r++) {
            for (int c=0; c<board[r].size(); c++) {
                if (!isdigit(board[r][c])) continue;
                int idx = board[r][c] - '0' -1;
                if (row_map[r][idx]==true) {
                    return false;
                }
                row_map[r][idx]=true;
                if (col_map[c][idx]==true) {
                    return false;
                }
                col_map[c][idx]=true;
                int b = (r/3)*3 + c/3;
                if (blk_map[b][idx]==true) {
                    return false;
                }
                blk_map[b][idx]=true;
            }
        }
        return true;
    }
};