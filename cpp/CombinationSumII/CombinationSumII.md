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

####解法1

__Code:__

	class Solution {
	private:
	    vector<vector<int> > ret;
	    vector<int> a;
	public:
	    void solve(int dep, int maxDep, vector<int> &num, int target)
	    {
	        if (target < 0)
	            return;
	            
	        if (dep == maxDep)
	        {
	            if (target == 0)
	            {
	                vector<int> res;
	                for(int i = 0; i < maxDep; i++)
	                    for(int j = 0; j < a[i]; j++)
	                        res.push_back(num[i]);
	                ret.push_back(res);
	            }
	            
	            return;
	        }
	        
	        for(int i = 0; i <= min(target / num[dep], 1); i++)
	        {
	            a[dep] = i;
	            
	            if (i == 1 && dep > 0 && num[dep-1] == num[dep] && a[dep-1] == 0)
	                continue;
	                
	            solve(dep + 1, maxDep, num, target - i * num[dep]);
	        }
	    }
	    
	    vector<vector<int> > combinationSum(vector<int> &num, int target) {
	        // Start typing your C/C++ solution below
	        // DO NOT write int main() function
	        sort(num.begin(), num.end());
	        a.resize(num.size());
	        ret.clear();
	        if (num.size() == 0)
	            return ret;
	            
	        solve(0, num.size(), num, target);
	        
	        return ret;
	    }
	};

####解法2

__Code:__

	class Solution {  
	private:  
	    const int index_count;  
	    vector<vector<int> > results;  
	public:  
	    Solution() : index_count(10000) {};  
	    // index记录当前找到的候选数字，n表示当前正在找第几个，n是index的下标不是candidates的下标  
	    void backtrace(int target, int sum, vector<int> &candidates, int index[], int n)  
	    {  
	        if (sum > target)  
	        {  
	            return; // 回溯  
	        }  
	        if (sum == target)  
	        {  
	            vector<int> result;  
	            for (int i = 1; i <= n; ++i)  
	            {  
	                result.push_back(candidates[index[i]-1]);   // 这里需要减一，因为下面每次记录索引时加了1      
	            }  
	            results.push_back(result);  
	            return; // 此处可以不加，如果不加return由于都是正整数，到下面的计算时会多进行一次无用的递归。  
	        }  
	  
	        // 深度搜索，为了避免重复，每次从当前候选项索引到结尾，上面的i=index[n]可以看出  
	        for (int i = index[n]; i < candidates.size(); ++i)  
	        {  
	            index[n+1] = i+1;   // 记录当前考察的候选项索引并加一，下次考察是跳过上次考察过的元素，每轮每个元素值考察一次  
	            backtrace(target, sum+candidates[i], candidates, index, n+1);  
	        }  
	    }  
	    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {  
	        // Start typing your C/C++ solution below  
	        // DO NOT write int main() function  
	        sort(candidates.begin(), candidates.end());  
	  
	        int *index = new int[index_count];  
	        memset(index, 0, sizeof(int)*index_count);  
	  
	        results.clear();    // 提交到leetcode的测试系统上必须添加，它应该是使用一个对象测试所有测试用例。  
	        backtrace(target, 0, candidates, index, 0);  
	  
	        delete[] index;  
	  
	        // 去重  
	        vector<vector<int> >::iterator end = results.end();    
	        sort(results.begin(), end, less<vector<int> >());  
	        vector<vector<int> >::iterator new_end = unique(results.begin(), results.end());  
	        results.erase(new_end, end);  
	  
	        return results;  
	    }  
	}; 