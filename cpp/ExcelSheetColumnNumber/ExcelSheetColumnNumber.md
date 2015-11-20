###Excel Sheet Column Number
URL: https://leetcode.com/problems/excel-sheet-column-number/</br>
Related to question [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)</br>
Given a column title as appear in an Excel sheet, return its corresponding column number.</br>
For example:</br>

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 

__Code:__

	#include <stdio.h>
	#include <stdlib.h>
	#include <iostream>
	#include <string>
	using namespace std;

	//int->str
	string base26_int2str(long long n) {
	    string ret;
	    while(n>0){
	        char ch = 'A' + (n-1)%26;
	        ret.insert(ret.begin(), ch);
	        n -= (n-1)%26;
	        n /= 26;
	    }
	    return ret;
	}

	//str->int
	long long base26_str2int(string& s){
	    long long ret=0;
	    for (int i=0; i<s.size(); i++){
	        int n = s[i] - 'A' + 1;
	        ret = ret*26 + n;
	    }
	    return ret;
	}

	int main(int argc, char**argv)
	{
	    long long n = 27; 
	    if (argc>1){
	        n = atoll(argv[1]);						//1
	    }
	    string ns = base26_int2str(n);
	    n = base26_str2int(ns);

	    cout << n << " = " << ns << endl;


	    ns = "ABCDEFG";
	    if (argc>2){
	        ns = argv[2];
	    }
	    cout << ns << " = " << base26_str2int(ns) << endl;
	}

###1 atoll

头文件：`<stdlib.h>`

语法：

	long long atoll(const char *str);

Interprets an integer value in a byte string pointed to by `str`.</br>

Discards any whitespace characters until the first non-whitespace character is found, then takes as many characters as possible to form a valid integer number representation and converts them to an integer value. The valid integer value consists of the following parts:

- (optional) plus or minus sign
- numeric digits

####Parameters

- `str` - pointer to the null-terminated bytes string to be interpreted.

####Return value

Interger value corresponding to the contents of `str` on success. If the converted value falls out of range of corresponding return type, the return value is undefined. If no conversion can be performed, `0` is returned.