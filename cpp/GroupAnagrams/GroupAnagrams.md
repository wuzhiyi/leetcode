###Group Anagrams
URL: https://leetcode.com/problems/anagrams/</br>
Given an array of strings, group anagrams together.

For example, given: `["eat", "tea", "tan", "ate", "nat", "bat"]`, 
Return:

	[
	  ["ate", "eat","tea"],
	  ["nat","tan"],
	  ["bat"]
	]

####Note:
1. For the return value, each inner list's elements must follow the lexicographic order.
2. All inputs will be in lower-case.

__Code:__

	vector<vector<string>> groupAnagrams(vector<string>& strs) {
	        unordered_map<string, vector<string>> hashMap;
	        for(auto &v : strs) {
	            string tmp(v);
	            sort(tmp.begin(), tmp.end());
	            hashMap[tmp].push_back(v);
	        }
	        vector<vector<string>> result(hashMap.size());
	        int k = 0;
	        for(auto it = hashMap.begin(); it != hashMap.end(); ++it, ++k) {
	            result[k].swap(it->second);
	            sort(result[k].begin(), result[k].end());
	        }
	        return result;
	    }