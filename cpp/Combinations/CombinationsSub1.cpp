class Solution {
private:
    void helper(int n, int k, vector<int>& solution, vector<vector<int>>& result) {
        if (k==0) {
            vector<int> v = solution;
            sort(v.begin(), v.end());
            result.push_back(v);
            return;
        }
        for (int i=n; i>0; i--) {
            solution.push_back(i);
            helper(i-1, k-1, solution, result);
            solution.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> solution;
        helper(n, k, solution, result);
        return result;
    }
};