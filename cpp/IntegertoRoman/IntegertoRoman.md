###Integer to Roman
URL: https://leetcode.com/problems/integer-to-roman/</br>
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.

__Code:__

	#include <stdlib.h>
	#include <string>
	#include <iostream>
	using namespace std;

	//greeding algorithm
	string intToRoman(int num) {
		//初始化符号
	    string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	    //初始化数字
	    int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
	    string result;

	    for(int i=0; num!=0; i++){
	        while(num >= value[i]){
	        	//确定数字值范围，添加对应符号
	            num -= value[i];
	            result+=symbol[i];
	        }
	    }

	    return result;
	}


	int main(int argc, char** argv)
	{
	    int num = 1234;
	    if (argc>0){
	        num = atoi(argv[1]);
	    }    

	    cout << num << " : " << intToRoman(num) << endl;
	    return 0;
	}