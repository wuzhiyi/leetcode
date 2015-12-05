###Subsets
URL: https://leetcode.com/problems/subsets/</br>
Given a set of distinct integers, _nums_, return all possible subsets.

####Note:
- Elements in a subset must be in non-descending order.
- The solution set must not contain duplicate subsets.

For example,</br>
If ___nums___ = `[1,2,3]`, a solution is:

	[
	  [3],
	  [1],
	  [2],
	  [1,2,3],
	  [1,3],
	  [2,3],
	  [1,2],
	  []
	]

参考：http://blog.csdn.net/feliciafay/article/details/18976383

####迭代版

	//9ms
	class Solution {
	public:
	    vector<vector<int> > subsets(vector<int> &S) {
	       sort(S.begin(), S.end());
	       vector<vector<int> > result(1); 
	       for (int i = 0; i < S.size(); ++i) {
	           int length = result.size();
	           for (int j = 0; j < length; ++j) {
	               result.push_back(result[j]);
	               result.back().push_back(S[i]);
	           }
	       }
	       return result;
	    }
	};

####DFS递归版

	class Solution {
	public:
	    // void print_vector(vector<int> v) {
	    //     for (int i=0; i < v.size(); ++i) {
	    //         std::cout<<v[i]<<"\t";
	    //     }
	    //     std::cout<<std::endl;
	    // }
	    void helper(vector<int> &S, vector<int> &every,  vector<vector<int> > &final, int begin, int end) {
	        for (int i = begin; i < end; ++i) {
	            every.push_back(S[i]);
	            final.push_back(every);
	            helper(S, every, final, i + 1, end);
	            every.pop_back();
	        }
	    }
	    vector<vector<int> > subsets(vector<int> &S) {
	        vector<vector<int> > final(1);
	        vector<int> every;
	        sort(S.begin(), S.end());
	        int start = 0;
	        helper(S, every, final, start, (int)S.size());
	        return final;
	    }
	};