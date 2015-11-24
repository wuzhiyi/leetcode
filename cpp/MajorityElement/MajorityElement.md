###169 Majority Element
URL: https://leetcode.com/problems/majority-element/</br>
Given an array of size _n_, find the majority element. The majority element is the element that appears more than `⌊ n/2 ⌋` times.</br>
You may assume that the array is non-empty and the majority element always exist in the array.

__Code:__


##1 class std::stringstream

格式：

	typedef basic_stringstream<char> stringstream;

Objects of this `stringstream` use a _string buffer_ that contains a sequence of characters. This sequence of characters can be accessed directly as a `string` object, using member `str`.

##2 std::istream::getline

格式：

	istream& getline (char* s, streamsize n);
	istream& getline (char* s, streamszie n, char delim);

从流中提取字符作为无格式输入，并将它们储存到 _s_ 中作为一个 c-string，直到被提取的字符是分隔符，或者 n 个字符已经被写入 _s_ (包括终止符 null).

##3 std::string::c_str

格式：

	//C++98
	const char* c_str() const;
	//C++11
	const char* c_str() const noexcept;

返回一个指针，该指针指向包含一个以 null 结束的字符串的数组，作为目前字符串对象的值。</br>
这个数组包括相同的字符串加上末尾的一个空字符 `'\0'`.
