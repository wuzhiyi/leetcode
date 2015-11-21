###Combination Sum
URL: https://leetcode.com/problems/combination-sum/</br>
Given a set of candidate numbers (___C___) and a target number (___T___), find all unique combinations in ___C___ where the candidate numbers sums to ___T___.

The __same__ repeated number may be chosen from ___C___ unlimited number of times.

####Note:
All numbers (including target) will be positive integers.</br>
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).</br>
The solution set must not contain duplicate combinations.</br>
For example, given candidate set `2,3,6,7` and target `7`, </br>
A solution set is: </br>
`[7]` </br>
`[2, 2, 3]` </br>

__Code:__

	#include <iostream>
	#include <vector>
	#include <algorithm>
	using namespace std;


	void combinationSumHelper(vector<int> &candidates, int start, int target, vector<int> &solution, vector< vector<int> > &result) {
	    if (target<0){
	        return;
	    }
	    if (target==0){
	        result.push_back(solution);
	        return;
	    }
	    for(int i=start; i<candidates.size(); i++){
	        //skip duplicates
	        if (i>start && candidates[i] == candidates[i-1]) {
	            continue;
	        }
	        solution.push_back(candidates[i]);
	        combinationSumHelper(candidates, i, target - candidates[i], solution, result);
	        solution.pop_back();
	    }
	}

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
	    vector< vector<int> > result;
	    if (candidates.size()<=0){
	        return result;
	    }
	    sort(candidates.begin(), candidates.end());
	    
	    vector<int> solution;
	    combinationSumHelper(candidates, 0, target, solution, result);

	    return result;
	}

	void printMatrix(vector< vector<int> > &vv)
	{
	    for(int i=0; i<vv.size(); i++) {
	        cout << "[";
	        for(int j=0; j<vv[i].size(); j++) {
	            cout << " " << vv[i][j];
	        }
	        cout << "]" << endl;;
	    }
	}

	void printArray(vector<int> &v)
	{
	    cout << "{";
	    for(int i=0; i<v.size(); i++) {
	        cout << " " << v[i];
	    }
	    cout << "}" << endl;
	}


	int main(int argc, char** argv)
	{
	    int a[] = {4,2,3,3,5,7};
	    vector<int> v(a, a+sizeof(a)/sizeof(int));
	    int target = 7;
	    cout << "array  = ";
	    printArray(v);
	    cout << "target = " << target << endl;
	    
	    vector< vector<int> > vv = combinationSum(v, target);
	    printMatrix(vv);

	    return 0;
	}