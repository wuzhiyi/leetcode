###Word Pattern
URL: https://leetcode.com/problems/word-pattern/</br>
Given a `pattern` and a string `str`, find if `str` follows the same pattern.</br>
Here __follow__ means a full match, such that there is a bijection between a letter in `pattern` and a __non-empty__ word in `str`.

__Examples:__
1. pattern = `"abba"`, str = `"dog cat cat dog"` should return true.
2. pattern = `"abba"`, str = `"dog cat cat fish"` should return false.
3. pattern = `"aaaa"`, str = `"dog cat cat dog"` should return false.
4. pattern = `"abba"`, str = `"dog dog dog dog"` should return false.

__Notes:__
You may assume `pattern` contains only lowercase letters, and `str` contains lowercase letters separated by a single space.

__Code:__

	#include <stdlib.h>
	#include <vector>
	#include <iostream>
	#include <unordered_map>
	#include <sstream>

	using namespace std;

	class Solution {
	private:
	    
	    vector<string> split(string str, char delimiter) {
	        vector<string> internal;
	        stringstream ss(str); // Turn the string into a stream.
	        string tok;
	        
	        while(getline(ss, tok, delimiter)) {
	            internal.push_back(tok);
	        }
	        
	        return internal;
	    }
	    
	public:
	    
	    bool wordPattern(string pattern, string str) {
	        unordered_map<char, string> dict_pattern;
	        unordered_map<string, char> dict_string;
	        
	        int len = pattern.size();
	        vector<string> strs = split(str, ' ');
	        
	        if (len != strs.size()) return false;
	        
	        for(int i=0; i<len; i++) {
	            char& ch = pattern[i];
	            string& s = strs[i];
	            
	            if (dict_pattern.find(ch) == dict_pattern.end()) {
	                dict_pattern[ch] = s;
	            }
	            
	            if (dict_string.find(s) == dict_string.end()) {
	                dict_string[s] = ch;
	            }
	            
	            if (dict_pattern[ch] != s || dict_string[s] != ch) {
	                return false;
	            }
	            
	        }
	        return true;
	    }
	};

	int main(int argc, char** argv) {
		//输入pattern和string
	    string str1 = "abba";
	    string str2 = "dog cat cat dog";
	    //初始化一个Solution变量
	    Solution sol;
	    //验证，打印结果
	    if (sol.wordPattern(str1, str2)) {
	        cout << "True" << endl;
	    } else {
	        cout << "False" << endl;
	    }
	    
	    return 0;
	}