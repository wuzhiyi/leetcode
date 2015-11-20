###Valid Parentheses
URL: https://leetcode.com/problems/valid-parentheses/</br>
Given a string containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.</br>
The brackets must close in the correct order, `"()"` and `"()[]{}"` are all valid but `"(]"` and `"([)]"` are not.

__Code:__

	/* 对以下代码我有点不解，就是在while结构中，char rch=stack.back()
	 * 但是这个stack是空的，未被赋值
	 */

	#include <iostream>
	#include <string>
	using namespace std;

	bool isValid(string s) {

	    string stack;

	    while(s.size()>0){
	    	//lastcharacter
	        char lch = s.back();								//1
	        //如果最右字符为[,{,(,返回false
	        if (lch == '[' || lch=='{' || lch=='(') {
	            if (s.size()<=0) return false;
	            char rch = stack.back();
	            if ((lch=='[' && rch ==']') ||
	                    (lch=='{' && rch =='}') ||
	                    (lch=='(' && rch ==')') ) {
	                s.pop_back();								//2
	                stack.pop_back();
	            }else{
	                return false;
	            }
	        } else if (lch== ']' || lch=='}' || lch==')' ) {
	            s.pop_back();
	            stack.push_back(lch);							//3
	        } else {
	            //skip the other charactors
	            s.pop_back();
	        }
	    }
	    return (s.size()==0 && stack.size()==0 );
	}

	int main(int argc, char**argv)
	{
	    string s = "{{}{[]()}}";
	    if (argc>1){
	        s = argv[1];
	    }
	    cout << "str = \"" << (s) << "\"" << endl;
	    cout << isValid(s) << endl;
	}

###1 std::basic_string::back

####Syntax:

	CharT& back();
	const CharT& back() const;

Returns reference to the last character in the string. The behavior is undefined if `emtpy()==true`.

####Return value

Reference to the last character, equivalent to `operator[](size()-1)`.

###2 string::pop_back

####Syntax:

	void pop_back();

Removes the last character from the string.</br>
Equivalent to `erase(size()-1, 1)`, except the behavior is undefined if the string is empty.

###3 string::push_back

####Syntax:

	void push_back( CharT ch );

Appends the given character `ch` to the end of the string.

####Parameters

`ch` - the character to append.
