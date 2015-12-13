###Minimum Path Sum
URL: https://leetcode.com/problems/minimum-path-sum/</br>
Given a _m_ x _n_ grid filled with non-negative numbers, find a path from top left to bottom right which _minimizes_ the sum of all numbers along its path.

__Note:__ You can only move either down or right at any point in time.

__Code:__

	int minPathSum(vector<vector<int> > &grid) {
	    if (grid.size()<=0){
	        return 0;
	    }
	    int i, j;
	    for(i=0; i<grid.size(); i++){
	        for(j=0; j<grid[i].size(); j++){
	            int top = i-1<0 ? INT_MAX : grid[i-1][j] ;
	            int left = j-1<0 ? INT_MAX : grid[i][j-1];
	            if (top==INT_MAX && left==INT_MAX){
	                continue;
	            }
	            grid[i][j] += (top < left? top: left);

	        }
	    }

	    return grid[grid.size()-1][grid[0].size()-1];
	}