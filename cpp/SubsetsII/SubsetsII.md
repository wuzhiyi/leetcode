###Subsets II
URL: https://leetcode.com/problems/subsets-ii/</br>
Given a collection of integers that might contain duplicates, ___nums___, return all possible subsets.

####Note:
- Elements in a subset must be in non-descending order.
- The solution set must not contain duplicate subsets.

For example,</br>
If ___nums___ = `[1,2,2]`, a solution is:

	[
	  [2],
	  [1],
	  [1,2,2],
	  [2,2],
	  [1,2],
	  []
	]

__Code:__

	void getCombination(vector<int>& v, int n, int k, vector<int>& solution, vector< vector<int> >& result );
	vector<vector<int> > combine(vector<int>& v, int k); 
	vector<vector<int> > combine1(vector<int>& v, int k); 
	vector<vector<int> > combine2(vector<int>& v, int k);

	vector<vector<int> > subsets(vector<int> &S) {
	    vector<vector<int> > result;
	    sort(S.begin(), S.end());
	    for(int i=0; i<=S.size(); i++){
	        vector<vector<int> > r = combine(S, i); 
	        result.insert(result.end(), r.begin(), r.end()); 
	    } 
	    return result;
	}


	vector<vector<int> > combine(vector<int> &v, int k) {
	    vector<vector<int> > result;
	    vector<int> solution;
	    getCombination(v, v.size(), k, solution, result);
	    return result;
	}

	void getCombination(vector<int> &v, int n, int k, vector<int>& solution, vector< vector<int> >& result ){
	    if (k==0){
	        //sort to meet LeetCode requirement
	        vector<int> v = solution;
	        sort(v.begin(), v.end());
	        result.push_back(v);
	        return;
	    }
	    for(int i=n; i>0; i--){
	        solution.push_back(v[i-1]);
	        getCombination(v, i-1, k-1, solution, result);
	        solution.pop_back();
	        //skip the duplication
	        while (i>1 && v[i-1]==v[i-2]) i--;
	   }
	}