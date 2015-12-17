/* Runtime Error
 */

class Solution {
private:
    int getCount(vector<vector<int>>& board, int r, int c) {
        int cnt=0;
        for (int i=r-1; i<r+2; i++) {
            for (int j=c-1; j<c+2; j++) {
                if (i==r && j==c) continue;
                if (board[i][j]==1) cnt++;
            }
        }
        return cnt;
    }
    void liveUpdate(vector<vector<int>>& board, int r, int c) {
        if (getCount(board, r, c)!=2 || getCount(board, r, c)!=3) {
            board[r][c] = 0;
        }
    }
    void dieUpdate(vector<vector<int>>& board, int r, int c) {
        if (getCount(board, r, c)==3) {
            board[r][c] = 1;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.size()<1) return;
        for (int r=0; r<board.size(); r++) {
            for (int c=0; c<board.size(); c++) {
                if (board[r][c]==1) {
                    liveUpdate(board, r, c);
                } else {
                    dieUpdate(board, r, c);
                }
            }
        }
    }
};