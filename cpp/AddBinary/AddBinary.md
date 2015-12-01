###Add Binary
URL: https://leetcode.com/problems/add-binary/</br>
Given two binary strings, return their sum (also a binary string).</br>
For example,</br>
a = `"11"`</br>
b = `"1"`</br>
Return `"100"`.

__Code:__

	#include <iostream>
	#include <string>
	using namespace std;

	string addBinary(string a, string b) {
	    int alen = a.size();												//1	
	    int blen = b.size();
	    //进位标示carry
	    bool carry = false;
	    string result;
	    while( alen>0 || blen>0) {
	    	//若alen<=0,abit=0;否则,abit=a[alen-1]-'0'
	        int abit = alen<=0 ? 0 : a[alen-1]-'0';
	        int bbit = blen<=0 ? 0 : b[blen-1]-'0';
	        int cbit = carry ? 1 : 0;
	        result.insert(result.begin(), '0' + ((abit+bbit+cbit) & 1));	//2,3
	        carry = (abit+bbit+cbit>1);
	        alen--; blen--;
	    }
	    if (carry){
	        result.insert(result.begin(), '1');
	    }
	    return result;
	}


	int main(int argc, char** argv) 
	{
	    string a = "11";
	    string b = "1";
	    if (argc>2){
	        a = argv[1];
	        b = argv[2];
	    }

	    cout << a << "+" << b << "=" << addBinary(a, b) << endl;
	    
	}

###1 std::basic_string::size

语法：

	size_type size() const;
	size_type length() const;

返回 string 中字符元素的数量，例如：`std::distance(begin(), end())`.

###2 std::basic_string::insert
	
	//1
	basic_string& insert( size_type index, size_type count, CharT ch );	
	//2		
	basic_string& insert( size_type index, const CharT* s );	
	//3				
	basic_string& insert( size_type index, const CharT* s, size_type count );
	//4
	basic_string& insert( size_type index, const basic_string& str );
	//5		
	basic_string& insert( size_type index, const basic_string& str,
	                      size_type index_str, size_type count );				//until C++14
	basic_string& insert( size_type index, const basic_string& str,
	                      size_type index_str, size_type count = npos);			//since C++14	
	//6
	iterator insert( iterator pos, CharT ch );									//until C++11
	iterator insert( const_iterator pos, CharT ch );							//since C++11
	//7
	void insert( iterator pos, size_type count, CharT ch );						//until C++11
	iterator insert( const_iterator pos, size_type count, CharT ch );			//since C++11
	//8
	template< class InputIt >
	void insert( iterator pos, InputIt first, InputIt last );					//until C++11
	template< class InputIt >
	iterator insert( const_iterator pos, InputIt first, InputIt last );			//since C++11
	//9
	iterator insert( const_iterator pos, std::initializer_list<CharT> ilist );	//since C++11

将字符插入 string 中：

1. Inserts `count` copies of character ch at the position index.
2. Inserts null-terminated character string pointed to by s at the position `index`. The length of the string is determined by the first null character (effectively calls `Traits::length(s)`.
3. Inserts the first `count` characters from the character string pointed to by `s` at the position `index`. `s` can contain null characters.
4. Inserts string `str` at the position index.
5. Inserts a string, obtained by `str.substr(index_str, count)` at the position `index`.
6. Inserts character `ch` before the character pointed by `pos`.
7. Inserts count `copies` of character `ch` before the element pointed by `pos`.
8. Inserts characters from the range `[first, last)` before the element pointed by `pos`. This overload does not participate in overload resolution if `InputIt` does not satisfy `InputIterator`. (since C++11)
9. Inserts elements from initializer list `ilist` before the element pointed by `pos`.

###3 operator&

	template< std::size_t N >
	bitset<N> operator&( const bitset<N>& lhs, const bitset<N>& rhs );		//1
	template< std::size_t N >
	bitset<N> operator|( const bitset<N>& lhs, const bitset<N>& rhs );		//2
	template< std::size_t N >
	bitset<N> operator^( const bitset<N>& lhs, const bitset<N>& rhs );		//3

Performs binary AND, OR, and XOR between two bitsets, lhs and rhs.

1. Returns a `bitset<N>` containing the result of binary AND on corresponding pairs of bits of `lhs` and `rhs`.
2. Returns a `bitset<N>` containing the result of binary OR on corresponding pairs of bits of `lhs` and `rhs`.
3. Returns a `bitset<N>` containing the result of binary XOR on corresponding pairs of bits of `lhs` and `rhs`.

####Parameters

- `lhs` - the bitset on the left-hand side of the operator.
- `rhs` - he bitset on the right-hand side of the operator.
