###27 Remove Element
URL: https://leetcode.com/problems/remove-element/</br>
Given an array and a value, remove all instances of that value in place and return the new length.</br>
The order of elements can be changed. It doesn't matter what you leave beyond the new length.</br>

__Code:__

	class Solution {
	public:
	    int removeElement(int A[], int n, int elem) {
	    	//尾部标记
	        int tail = n-1;
	        //跳蛋初始化
	        int i = 0;
	        while (i <= tail){
	        	//如果跳蛋所在元素等于elem，等于数组最后一个元素，并重新判断一次
	            if (A[i] == elem) {
	                A[i] = A[tail--];
	                //跳出循环，重新判断(A[i] == elem)
	                continue;							//1
	            }
	            i++;
	        }
	        return tail+1;
	    }
	};

###1 continue

break, continue 和 return 的区别：

- `break`	直接跳出当前的循环，从当前循环外面开始执行，忽略循环体中任何其他语句和循环条件测试。它只能跳出一层循环，如果循环是嵌套循环，那么需要按照嵌套的层次，逐步使用 break 来跳出.
- `continue`	也是终止当前的循环过程，但并不跳出循环，而是继续往下判断循环条件执行语句。只能结束循环中的一次过程，但不能终止循环继续进行。
- `return`	表示终止当前函数的运行，并将操作权返回给调用者。如果是在 main 函数中，表示将操作权返回给操作系统。

