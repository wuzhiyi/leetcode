###Isomorphic Strings
URL: https://leetcode.com/problems/isomorphic-strings/</br>
Given two strings ___s___ and ___t___, determine if they are isomorphic.</br>
Two strings are isomorphic if the characters in ___s___ can be replaced to get ___t___.</br>
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.</br>
For example,</br>
Given `"egg"`, `"add"`, return true.</br>
Given `"foo"`, `"bar"`, return false.</br>
Given `"paper"`, `"title"`, return true.

__Note:__
You may assume both ___s___ and ___t___ have the same length.

__Code:__

	class Solution {
	public:
	    bool isIsomorphic(string s, string t) {
	    	//判断s和t长度是否相等
	        if (s.size()!=t.size()) return false;
	        
	        const int MAXCHAR = 256;
	        char maps[MAXCHAR]={0}, mapt[MAXCHAR]={0};			//1
	        //memset(maps, 0, sizeof(maps));
	        //memset(mapt, 0, sizeof(mapt));
	        
	        for(int i=0; i<s.size(); i++){
	        	//将s和t中的字符直接映射到maps和mapt中
	            if(maps[s[i]] == 0 && mapt[t[i]] == 0){
	                maps[s[i]] = t[i];
	                mapt[t[i]] = s[i];
	                continue;
	            }
	            if(maps[s[i]] == t[i] && mapt[t[i]] == s[i]) {
	                continue;
	            }
	            return false;
	        }
	        return true;
	    }
	};

##1 char

字符字面值一般是用单引号 `' '` 来表示。char 类型一般就是用字符字面值来初始化、赋值。由于 char 类型的是单字节长度，当给 char 类型的变量用字符字面值赋值时，当单引号里面的内容超过一个字节时，系统会自动截取一个字节的内容给 char 变量，忽略其他的字节内容。

- 当给 char 变量赋值正确地用 ASII 表中的字符，比如 `char c='!'`，单引号里面的内容是什么，cout 就会输出什么。
- 当给 char 变量用一个整型字面字初始化时，比如 `char d=55`，这时系统会选择在该整型值在 ASII 表中代表的字符输出。