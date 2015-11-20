###String to Integer (atoi)
URL: https://leetcode.com/problems/string-to-integer-atoi/</br>
Implement atoi to convert a string to an integer.

__Hint:__ Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

__Notes:__ It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

####Update (2015-02-10):
The signature of the `C++` function had been updated. If you still see your function signature accepts a `const char *` argument, please click the reload button to reset your code definition.

####Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.</br>
The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.</br>
If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.</br>
If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, `INT_MAX (2147483647)` or `INT_MIN (-2147483648)` is returned.

__Code:__

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>

	//定义超出范围时的representable value
	#define INT_MIN     (-2147483647 - 1)
	#define INT_MAX      2147483647

	int atoi(const char *str) {
		//检查str
	    if (str==NULL || *str=='\0'){
	        return 0;
	    }
	    
	    int ret=0;
	    //找到str第一个空格字符
	    for(;isspace(*str); str++);						//1
	    //负号标记
	    bool neg=false;
	    if (*str=='-' || *str=='+') {
	    	//若有负号,neg=true
	        neg = (*str=='-') ;
	        str++;
	    }
	    
	    for(; isdigit(*str); str++) {					//2
	        //将*str指针指向的数字赋值给digit
	        int digit = (*str-'0');
	        //上下界检查
	        if(neg){
	            if( -ret < (INT_MIN + digit)/10 ) {
	                return INT_MIN;
	            }
	        }else{
	            if( ret > (INT_MAX - digit) /10 ) {
	                return INT_MAX;
	            }
	        }
	        //逐位合成整型数字
	        ret = 10*ret + digit ;
	    }
	    //确定正负号
	    return neg?-ret:ret;
	}


	int main()
	{
	    printf("\"%s\" = %d\n", "123", atoi("123"));
	    printf("\"%s\" = %d\n", "   123", atoi("    123"));
	    printf("\"%s\" = %d\n", "+123", atoi("+123"));
	    printf("\"%s\" = %d\n", " -123", atoi(" -123"));
	    printf("\"%s\" = %d\n", "123ABC", atoi("123ABC"));
	    printf("\"%s\" = %d\n", " abc123ABC", atoi(" abc123ABC"));
	    printf("\"%s\" = %d\n", "2147483647", atoi("2147483647"));
	    printf("\"%s\" = %d\n", "-2147483648", atoi("-2147483648"));
	    printf("\"%s\" = %d\n", "2147483648", atoi("2147483648"));
	    printf("\"%s\" = %d\n", "-2147483649", atoi("-2147483649"));
	    return 0;
	}

###1 std::isspace

头文件：`<cctype>`

语法：

	int isspace(int ch);

检查给定的字符是否是空格字符，C 默认的空格字符有：

- space (0x20, `' '`)
- form feed (0x0c, `'\f'`)
- line feed (0x0a, `'\n'`)
- carriage return (0x0d, `'\r'`)
- horizontal tab (0x09, `'\t'`)
- vertical tab (0x0b, `'\v'`)

如果 `ch` 的值不表示 `unsigned char` 或不等同于 `EOF`，那么将不会被定义.

如果字符为空格返回一个非 0 值，否则返回 0.

###2 std::isdigit

头文件：`<cctype>`

语法：

	int isdigit(int ch);

检查给定的字符是否是十进制数字: 0 1 2 3 4 5 6 7 8 9.

如果 `ch` 的值不表示 `unsigned char` 或不等同于 `EOF`，那么将不会被定义.

如果字符为十进制数字返回一个非 0 值，否则返回 0.