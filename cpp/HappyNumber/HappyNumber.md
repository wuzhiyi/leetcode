###Happy Number
URL: https://leetcode.com/problems/happy-number/</br>
Write an algorithm to determine if a number is "happy".</br>
A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.</br>
__Example:__ 19 is a happy number</br>
1^2 + 9^2 = 82</br>
8^2 + 2^2 = 68</br>
6^2 + 8^2 = 100</br>
1^2 + 0^2 + 0^2 = 1</br>

__Code:__

	#include <stdlib.h>
	#include <iostream>
	#include <map>							//1
	using namespace std;

	int squares(int n) {
	    int result = 0;
	    int sq = 0;
	    //求各个位数的平方和
	    for (; n>0; n/=10) {
	        sq = n%10;
	        result += (sq * sq);
	    }
	    return result;
	}

	bool isHappy(int n) {
		//判断特殊情况1
	    if (n==1) return true;

	    map<int, bool> m;					//1
	    m[n]=true;

	    //递归求n的squares
	    while (n!=1) {
	        n = squares(n);
	        //cout << n << endl;
	        if (m.find(n) != m.end()) {
	            return false;
	        }
	        m[n] = true;
	    }
	    return true;
	}


	int main(int argc, char** argv) 
	{
	    int n = 2;
	    if (argc > 1){
	        n = atoi(argv[1]);				//2
	    }
	    cout << n << (isHappy(n) ? " is " : " isn't ") << "a happy number" << endl;
	    return 0;
	}

##1 std::map

头文件：`<map>`

格式：

	template < class Key,									//map::key_type
			   class T,										//map::mapped_type
			   class Compare = less<Key>,					//map::key_compare
			   class Alloc = allocator<pair<const Key,T>>	//map::allocator_type
			   > class map;

map 是关联容器，它存储的元素由一个 _key value_ 和一个 _mapped value_ 组成，并遵循特定的顺序。</br>
在 map 中，_key value_ 一般用来排序或唯一识别元素，而 _mapped value_ 则是储存与 key 对应的内容。

##2 atoi()

####atoi()

函数原型为：

	int atoi(char *str)

用途是将字符串转换成一个整数值，str 是待转化成整数值的字符串。成功则返回转化后的整数值，失败则返回 0.

####substr()

函数原型为：

	basic string::substr(string, start, length)
	//也可以写成
	string &a,
	a.substr(start, length);
	//其中a是待截取的字符串，start表示从截取开始的前一位，length表示截取长度

####c_str()

函数原型为：

	const char *c_str()

c_str() 将 string 对象转化为 char* 对象，返回一个客户程序可读不可改的指向字符数组的指针。