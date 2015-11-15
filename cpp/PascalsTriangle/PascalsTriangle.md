###118 Pascal's Triangle
URL: https://leetcode.com/problems/pascals-triangle/</br>
Given _numRows_, generate the first _numRows_ of Pascal's triangle.</br>
For example, given _numRows_ = 5,</br>
Return

	[
	     [1],
	    [1,1],
	   [1,2,1],
	  [1,3,3,1],
	 [1,4,6,4,1]
	]

__Code:__

	#include <stdlib.h>
	#include <vector>
	#include <iostream>
	using namespace std;												//1

	//二维向量vector<vector<int>>类型函数
	//生成
	vector<vector<int>> generate(int numRows) 
	{
		//定义二维数组
	    vector<vector<int> > pascalTriangle;
	    for (int i=0; i<numRows; i++){
	    	//每次循环初始化一次v数组
	        vector<int> v;
	        if (i==0){
	        	//在vector末尾增加新元素，其值为1
	            v.push_back(1);											//2
	        } else {
	            v.push_back(1);
	            for(int j=0; j<pascalTriangle[i-1].size()-1; j++){		//3
	            	//把pascal上一行两个元素相加，并将其和加入v数组中
	                v.push_back(pascalTriangle[i-1][j] + pascalTriangle[i-1][j+1]);
	            }
	            v.push_back(1);
	        }
	        //将v数组加入二维数组pascal中
	        pascalTriangle.push_back(v); 
	    }
	    return pascalTriangle;
	}

	//打印
	void printTriangle(vector< vector<int> > pt)
	{
		cout << "[" << endl;											//4
	    for(int i=0; i<pt.size(); i++){
	    	for(int space=(pt.size()-i-1); space>=0; space--){
	    		cout << " ";
	    	}
	        cout << "[";
	        for(int j=0; j<pt[i].size(); j++){
	            cout << pt[i][j];
	            if(j<pt[i].size()-1){
	            	cout << ",";
	            }
	        }
	        cout << "]";
	        if(i<pt.size()-1){
	        	cout << ",";
	        }
	        cout << endl;
	    }
	    cout << "]" << endl;
	}

	int main(int argc, char** argv)
	{
	    int n = 3;
	    if (argc>1) {
	        n = atoi(argv[1]);
	    }
	    //打印(生成)
	    printTriangle(generate(n)); 
	}

##1 using namespace std;

C++ 标准库程序中的所有标识符都被定义于一个名为 std 的 namespace 中。由于 namespace 的概念，使用任何 C++ 标准库的任何标识符时，可以有三种选择：

1 __直接指定标识符__，例如：

	std::cout<<std::hex<<3.4<<std::endl;

2 __使用 using 关键字__，例如：

	using std::cout;
	using std::endl;
	using std::cin;

	cout << hex << 3.4 << endl;

3 __使用 using namespace std__，例如：

	#include<iostream>
	#include<sstream>
	#include<string>
	using namespace std;

不过尽量少在头文件中使用 using namespace std，防止名字空间污染。

##2 std::vector::push_back

使用格式（C++11）：

	void push_back (const value_type& val);
	void push_back (vlaue type&& val);

在 vector 当前最后一个元素后添加一个新的元素，并把 _val_ 的内容复制到新的元素。

容器容量实际增加 1.

##3 std::vector::size

使用格式：

	//C++98
	size_type size() const:
	//C++11
	size_type size() const noexcept;

返回 vector 中元素个数。

##4 cout << endl;

- `end'` 是在输出结束处插入一个新行，并清除缓冲区.
- `'\n'` 只是一个换行符.