###Game of Life
URL: https://leetcode.com/problems/game-of-life/</br>
According to the [Wikipedia's article](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life): "The __Game of Life__, also known simply as __Life__, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with _m_ by _n_ cells, each cell has an initial state _live_ (1) or _dead_ (0). Each cell interacts with its [eight neighbors](https://en.wikipedia.org/wiki/Moore_neighborhood) (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

1. Any live cell with fewer than two live neighbors dies, as if caused by under-population.
2. Any live cell with two or three live neighbors lives on to the next generation.
3. Any live cell with more than three live neighbors dies, as if by over-population..
4. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.

Write a function to compute the next state (after one update) of the board given its current state.

####Follow up: 
1. Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
2. In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?

__Analysis:__
最后我们对所有状态对2取余，那么状态0和2就变成死细胞，状态1和3就是活细胞，达成目的。我们先对原数组进行逐个扫描，对于每一个位置，扫描其周围八个位置，如果遇到状态1或2，就计数器累加1，扫完8个邻居，如果少于两个活细胞或者大于三个活细胞，而且当前位置是活细胞的话，标记状态2，如果正好有三个活细胞且当前是死细胞的话，标记状态3。完成一遍扫描后再对数据扫描一遍，对2取余变成我们想要的结果。参见代码如下：

__Code:__

	class Solution {
	public:
	    void gameOfLife(vector<vector<int> >& board) {
	        int m = board.size(), n = m ? board[0].size() : 0;
	        int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
	        int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	        for (int i = 0; i < m; ++i) {
	            for (int j = 0; j < n; ++j) {
	                int cnt = 0;
	                for (int k = 0; k < 8; ++k) {
	                    int x = i + dx[k], y = j + dy[k];
	                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
	                        ++cnt;
	                    }
	                }
	                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
	                else if (!board[i][j] && cnt == 3) board[i][j] = 3;
	            }
	        }
	        for (int i = 0; i < m; ++i) {
	            for (int j = 0; j < n; ++j) {
	                board[i][j] %= 2;
	            }
	        }
	    }
	};