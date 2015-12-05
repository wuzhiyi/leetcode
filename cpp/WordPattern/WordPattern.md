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

####解法1

	class Solution {
	public:
	    bool wordPattern(string pattern, string str) {
	        unordered_map<char, string> map1;
	        unordered_map<string, char> map2;
	        vector<string> vec;
	        //标记起始位置
	        int count = 0;
	        //根据' '拆分str，逐个赋值到容器vec中
	        for (int i=0; i<str.size(); i++) {
	            if (str[i] == ' ') {
	                string tmp = str.substr(count, i-count);
	                vec.push_back(tmp);
	                count = i+1;
	            }
	            if (i==str.size() - 1) {
	                string tmp = str.substr(count, i-count+1);
	                vec.push_back(tmp);
	            }
	        }
	        if (pattern.size() != vec.size()) return false;
	        //两个map交叉映射
	        for (int j=0; j<pattern.size(); j++) {
	            if (map1.find(pattern[j])==map1.end() && map2.find(vec[j])==map2.end()) {
	                map1.insert(make_pair(pattern[j], vec[j]));
	                map2.insert(make_pair(vec[j], pattern[j]));
	            } else if (map1[pattern[j]]!=vec[j] || map2[vec[j]]!=pattern[j]) {
	                return false;
	            }
	        }
	        return true;
	    }
	};

__Code:__

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