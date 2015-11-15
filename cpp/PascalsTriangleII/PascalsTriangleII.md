###119 Pascal's Triangle II
URL: https://leetcode.com/problems/pascals-triangle-ii/</br>
Given an index _k_, return the _kth_ row of the Pascal's triangle.</br>
For example, given _k_ = 3,</br>
Return `[1,3,3,1]`.

Note:
Could you optimize your algorithm to use only _O(k)_ extra space?

__Code:__

	#include <stdlib.h>
	#include <vector>
	#include <iostream>
	using namespace std;

	vector<int> getRow(int rowIndex) {
		//vector c(n,elem); 创建一个含有n个0的vector
	    vector<int> v(rowIndex+1, 0);
	    v[0]=1;

	    //构建PascalTri
	    for (int i=0; i<rowIndex; i++){
	        for(int j=i+1; j>0; j--){
	           v[j] += v[j-1];
	        } 
	    }
	    return v;
	    
	}

	void printVector(vector<int>  pt) {
	    cout << "{ ";
	    for(int j=0; j<pt.size(); j++){
	        cout << pt[j] << ", ";
	    }
	    cout << "} " << endl;
	}

	int main(int argc, char** argv) {		//1
	    int n = 3;
	    if (argc>1) {  
	        n = atoi(argv[1]);
	    }
	    printVector(getRow(n)); 
	}

##1 int main(int argc, char** argv)

`argc` 是指命令行输入参数的个数，`argv` 储存了所有的命令行参数。

`argv` 是指针的指针, 写法：

	char **argv
	char *argv[]
	char argv[][]

