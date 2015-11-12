###66 Plus One
URL: https://leetcode.com/problems/plus-one/</br>
Given a non-negative number represented as an array of digits, plus one to the number.</br>
The digits are stored such that the most significant digit is at the head of the list.

Code:
	
	#include <iostream>
	#include <vector>
	using namespace std;

	//函数类型vector<int>, 函数名plusOne, 变量类型vector<int>
	vector<int> plusOne(vector<int> &digits) {
		//整型变量carry，值为1
	    int carry = 1;
	    //vector <int> 类型变量v
	    vector <int> v;										//1
	    //digits中存在元素
	    while(digits.size()>0){								//2
	    	//若整数x等于digits最后一个元素
	        int x = digits.back();							//3
	        //容器大小减一，同时删除最后一个元素
	        digits.pop_back();								//4
	        x = x + carry;
	        //在vector第一个元素前插入x%10,并返回该元素iterator
	        v.insert(v.begin(), x%10);						//5
	        carry = x/10;
	    }
	    //如果carry大于0
	    if (carry>0){
	    	//在vector第一个元素前插入carry
	        v.insert(v.begin(), carry);
	    }
	    return v;

	}

	//打印vector
	void printVector(vector<int>& v)
	{
	    cout << "{ ";
	    for(int i=0; i<v.size(); i++){
	        cout << v[i] << " ";
	    }
	    cout << "} " << endl;
	}


	int main()
	{
	    int a[]={9,9,9};
	    vector<int> d(&a[0], &a[0]+sizeof(a)/sizeof(int));	//6
	    vector<int> v = plusOne(d);
	    printVector(v);
	    return 0;
	}

###1 vector初始化

	vector<类型> 标识符;
	vector<类型> 标识符 (最大容量);
	vector<类型> 标识符 (最大容量，初始所有值);

###2 std::vector::size

返回 vector 容器中元素的个数。
This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.

###3 std::vector::back

返回 vector 中最后一个元素的 reference
不同于 `vector::end` (returns an iterator just pass this element), `vector::back` returns a direct reference.

###4 std::vector::pop_back

删除 vector 中最后一个元素，实际上是容量大小减一。

###5 std::vector::insert

C++98:

	//single element (1)
	iterator insert (iterator position, const value_type& val);
	//fill (2)	
    void insert (iterator position, size_type n, const value_type& val);
	//range (3)	
	template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last);

C++11:
	
	//single element (1)	
	iterator insert (const_iterator position, const value_type& val);
	//fill (2)	
	iterator insert (const_iterator position, size_type n, const value_type& val);
	//range (3)	
	template <class InputIterator>
	iterator insert (const_iterator position, InputIterator first, InputIterator last);
	//move (4)	
	iterator insert (const_iterator position, value_type&& val);
	//initializer list (5)	
	iterator insert (const_iterator position, initializer_list<value_type> il);

在 vector 中的指定元素之前插入新元素，并且 vector 的容量增加插入新元素的数量。
当且仅当，新 vector 容量大小超过现在 vector 容量，会导致重置存储空间。

###6 sizeof()的定义和语法

sizeof 是一个操作符 (operator). 其作用是返回一个对象或类型所占的内存字节数。其返回值类型为 `size_t` (size_t 在头文件 `stddef.h` 中定义，其依赖于编译系统的值，一半定义为 typedef unsigned).

sizeof 的三种语法形式：

	sizeof(obect);
	sizeof object;
	sizeof(type_name);
