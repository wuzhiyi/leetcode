###Number of Islands
URL: https://leetcode.com/problems/number-of-islands/</br>
Given a 2d grid map of `'1'`s (land) and `'0'`s (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

####Example 1:

	11110
	11010
	11000
	00000

Answer: 1

####Example 2:

	11000
	11000
	00100
	00011

Answer: 3

__Code:__

	void mark(vector<vector<char> >& grid, int r, int c){
	    if ( r<0 || r>=grid.size() ||
	            c<0 || c>=grid[0].size() ||
	            grid[r][c] != '1' ) {
	        return;
	    }

	    grid[r][c] = 'M';

	    //left
	    mark(grid, r, c+1);
	    //right
	    mark(grid, r, c-1);
	    //up
	    mark(grid, r-1, c);
	    //down
	    mark(grid, r+1, c);
	}

	int numIslands(vector<vector<char> >& grid) {
	    int result = 0;
	    for (int r=0; r<grid.size(); r++) {
	        for (int c=0; c<grid[r].size(); c++) {
	            if (grid[r][c] == '1') {
	                result++;
	                mark(grid, r, c);
	            }
	        }
	    }
	    return result;
	}