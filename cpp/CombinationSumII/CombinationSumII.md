###Combination Sum II
URL: https://leetcode.com/problems/combination-sum-ii/</br>
Given a collection of candidate numbers (___C___) and a target number (___T___), find all unique combinations in ___C___ where the candidate numbers sums to ___T___.</br>
Each number in ___C___ may only be used once in the combination.

####Note:

- All numbers (including target) will be positive integers.
- Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
- The solution set must not contain duplicate combinations.

For example, given candidate set `10,1,2,7,6,1,5` and target `8`, </br>
A solution set is: </br>
`[1, 7]` </br>
`[1, 2, 5]` </br>
`[2, 6]` </br>
`[1, 1, 6]` </br>

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
	        int n = candidates[i];
	        if (i>start && candidates[i] == candidates[i-1]) {
	            continue;
	        }
	        solution.push_back(n);
	        combinationSumHelper(candidates, i+1, target - n, solution, result);
	        solution.pop_back();
	    }
	}

	vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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

	void test(int a[], int len, int target)
	{
	    vector<int> v(a, a+len);
	    cout << "array  = ";
	    printArray(v);
	    cout << "target = " << target << endl;

	    vector< vector<int> > vv = combinationSum2(v, target);
	    printMatrix(vv);
	}

	int main(int argc, char** argv)
	{
	    #define TEST(a, t) test(a, sizeof(a)/sizeof(int), target)
	    int a[] = {4,2,3,3,5,7};
	    int target = 7;
	    TEST(a, target);

	    int b[] = {10,1,2,7,6,1,5};
	    target = 8;
	    TEST(b, target);

	    int c[] = {2,2,2};
	    target = 2;
	    TEST(c, target);

	    return 0;
	}
