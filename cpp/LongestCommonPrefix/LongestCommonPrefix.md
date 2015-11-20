###Longest Common Prefix
URL: https://leetcode.com/problems/longest-common-prefix/</br>
Write a function to find the longest common prefix string amongst an array of strings.

__Code:__

	#include <iostream>
	#include <string>
	#include <vector>
	using namespace std;


	string longestCommonPrefix(vector<string> &strs) {
	    string word;
	    //检查strs长度
	    if (strs.size()<=0) return word;

	    for(int i=1; i<=strs[0].size(); i++){
	    	//复制strs[0]到w
	        string w = strs[0].substr(0, i);							//1
	        bool match = true;
	        int j=1;
	        //以strs[0]为基准，进行比较
	        for(j=1; j<strs.size(); j++){
	            if (i>strs[j].size() || w!=strs[j].substr(0, i) ) {
	                match=false;
	                break;
	            }
	        }
	        if (!match) {
	            return word;
	        }
	        word = w;
	    }
	    return word;
	}

	int main()
	{
	    const char* s[]={"abab","aba","abc"};
	    //放入vector容器
	    vector<string> v(s, s+3);
	    cout << longestCommonPrefix(v) <<endl;
	}

###1 std::basic_string::substr

####Syntax:

	basic_string substr( size_type pos = 0,
						 size_type count = npos ) const;

Returns a substring `[pos, pos+count)`. If the requested substring extends past the end of the string, or if `count == npos`, the returned substring is `[pos, size())`.

####Parameters:

- `pos` - position of the first character to include
- `count` - length of the substring

####Return value

1. An empty string if pos == size().
2. String containing the substring [pos, pos+count).

