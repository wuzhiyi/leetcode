###Longest Valid Parentheses
URL: https://leetcode.com/problems/longest-valid-parentheses/</br>
Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.</br>
For `"(()"`, the longest valid parentheses substring is `"()"`, which has length = 2.</br>
Another example is `")()())"`, where the longest valid parentheses substring is `"()()"`, which has length = 4.</br>

__Code:__

	#include <iostream>
	#include <string>
	#include <vector>
	using namespace std;

	int longestValidParentheses(string s) {
	    int maxLen = 0;
	    int lastError = -1;
	    vector<int> stack;
	    for(int i=0; i<s.size(); i++){
	        if (s[i] == '('){
	            stack.push_back(i);
	        }else if (s[i] == ')') {
	            if (stack.size()>0 ){
	                stack.pop_back();
	                int len;
	                if (stack.size()==0){
	                    len = i - lastError;
	                } else {
	                    len = i - stack.back();
	                }
	                if (len > maxLen) {
	                    maxLen = len;
	                }
	            }else{
	                lastError = i;
	            }
	        }
	    }
	    return maxLen;
	}


	int main(int argc, char** argv)
	{
	    string s = ")()())";
	    if (argc>1){
	        s = argv[1];
	    }
	    cout << s << " : " << longestValidParentheses(s) << endl;
	    return 0;
	}