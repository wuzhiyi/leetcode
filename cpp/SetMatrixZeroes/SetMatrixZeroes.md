###Set Matrix Zeroes
URL: https://leetcode.com/problems/set-matrix-zeroes/</br>
Given a _m_ x _n_ matrix, if an element is 0, set its entire row and column to 0. Do it in place.

####Follow up:
Did you use extra space?</br>
A straight forward solution using O(_mn_) space is probably a bad idea.</br>
A simple improvement uses O(_m + n_) space, but still not the best solution.</br>
Could you devise a constant space solution?

__Code:__

	class Solution {
	public:
	    Solution(){
	    
	    void setZeroes1(vector<vector<int> > &matrix) {
	        
	        int bRow = false, bCol=false;
	        
	        for (int r=0; r<matrix.size(); r++){
	            for(int c=0; c<matrix[r].size(); c++){
	                if (matrix[r][c]==0){
	                    if (r==0) bRow = true;
	                    if (c==0) bCol = true;
	                    matrix[0][c] = matrix[r][0] = 0;
	                }
	            }
	        }
	        
	        for (int r=1; r<matrix.size(); r++){
	            for(int c=1; c<matrix[r].size(); c++){
	                if (matrix[0][c]==0 || matrix[r][0]==0) {
	                    matrix[r][c]=0;
	                }
	            }
	        }
	        if (bRow){
	            for(int c=0; c<matrix[0].size(); c++) matrix[0][c] = 0;
	        }
	        if (bCol){
	            for(int r=0; r<matrix.size(); r++) matrix[r][0] = 0;
	        }

	    }
	    
	    void setZeroes2(vector<vector<int> > &matrix) {

	        bool *row = new bool[matrix.size()]();
	        bool *col = new bool[matrix[0].size()]();
	        for (int r=0; r<matrix.size(); r++){
	            for(int c=0; c<matrix[r].size(); c++){
	                if (matrix[r][c]==0){
	                    row[r]=true;
	                    col[c]=true;
	                }
	            }
	        }
	        
	        for (int r=0; r<matrix.size(); r++){
	            for(int c=0; c<matrix[r].size(); c++){
	                if (row[r] || col[c]) {
	                    matrix[r][c]=0;
	                }
	            }
	        }
	    }
	};