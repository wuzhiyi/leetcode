###Combination Sum III
URL: https://leetcode.com/problems/combination-sum-iii/</br>
Find all possible combinations of ___k___ numbers that add up to a number ___n___, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.</br>
Ensure that numbers within the set are sorted in ascending order.

___Example 1:___</br>
Input: ___k___ = 3, ___n___ = 7</br>
Output:</br>

	[[1,2,4]]

___Example 2:___</br>
Input: ___k___ = 3, ___n___ = 9
Output:

	[[1,2,6], [1,3,5], [2,3,4]]

__Code:__

	void combinationSumHelper(vector<int>& candidates, int start, int num, int target, 
	                          vector<int>& solution, vector< vector<int> >& results) {
	    if (target < 0|| solution.size() > num){
	        return;
	    }
	    if (target == 0 && solution.size()==num){
	        results.push_back(solution);
	        return;
	    }
	    for (int i=start; i<candidates.size(); i++){
	        solution.push_back(candidates[i]);
	        combinationSumHelper(candidates, i+1, num, target-candidates[i], solution, results);
	        solution.pop_back();
	    }
	    
	}

	vector< vector<int> > combinationSum3(int k, int n) {
	    vector<int> v;
	    for (int i=1; i<=9; i++){
	        v.push_back(i);
	    }

	    vector< vector<int> > result;
	    vector<int> solution;

	    combinationSumHelper(v, 0, k, n, solution, result);    

	    return result;

	}