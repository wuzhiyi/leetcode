###Generate Parentheses
URL: https://leetcode.com/problems/generate-parentheses/</br>
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

`"((()))", "(()())", "(())()", "()(())", "()()()"`

__Code:__

	void generator(vector<string>& result, int left, int right, string s);
	vector<string> generateParenthesis(int n) {
	    
	    vector<string> result;
	    string s;
	    generator(result, n, n, s);
	    return result;
	}

	void generator(vector<string>& result, int left, int right, string s){
	    if (left==0 && right==0){
	        result.push_back(s);
	        return;
	    }
	    if (left>0){
	        generator(result, left-1, right, s+'(');
	    }
	    if (right>0 && right>left){
	        generator(result, left, right-1, s+')');
	    }
	}