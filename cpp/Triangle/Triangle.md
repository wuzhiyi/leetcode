###Triangle
URL: https://leetcode.com/problems/triangle/</br>
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.</br>
For example, given the following triangle

	[
	     [2],
	    [3,4],
	   [6,5,7],
	  [4,1,8,3]
	]

The minimum path sum from top to bottom is `11` (i.e., 2 + 3 + 5 + 1 = 11).

####Note:
Bonus point if you are able to do this using only O(_n_) extra space, where n is the total number of rows in the triangle.

__Code:__

	class Solution {
	    
	public:
	    int minimumTotal(vector<vector<int> > &triangle) {
	        vector< vector<int> > v;
	        
	        for (int i=0; i<triangle.size(); i++){
	            //最顶端
	            if(i==0){
	                v.push_back(triangle[i]);
	                continue;
	            }
	            
	            vector<int> tmp;
	            
	            for(int j=0; j<triangle[i].size(); j++){
	                int x, y, z;
	                x = y = z = 0x7fff;
	                if ( (j-1) >= 0){
	                    x = v[i-1][j-1];
	                }
	                if (j<v[i-1].size()) {
	                    y = v[i-1][j];
	                }
	                /* won't take the previous adjacent number */
	                //if ( (j+1)<v[i-1].size()) {
	                //    z = v[i-1][j+1];
	                //}
	                tmp.push_back( min(x,y,z) + triangle[i][j] );
	            }
	            
	            v.push_back(tmp);
	            
	        }
	        int min=0x7fff;
	        if (v.size() > 0){
	            vector<int> &vb = v[v.size()-1];
	            for(int i=0; i<vb.size(); i++){
	                if (vb[i] < min ){
	                    min = vb[i];
	                }
	            }
	        }
	           
	        return min;
	    }
	private:
	    inline int min(int x, int y, int z){
	        int n = x<y?x:y;
	        return (n<z?n:z);
	    }
	};