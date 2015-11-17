###Valid Anagram
URL: https://leetcode.com/problems/valid-anagram/</br>
Given two strings _s_ and _t_, write a function to determine if _t_ is an anagram of _s_.</br>
For example,</br>
s = "anagram", t = "nagaram", return true.</br>
s = "rat", t = "car", return false.</br>

__Note:__
You may assume the string contains only lowercase alphabets.

__Follow up:__
What if the inputs contain unicode characters? How would you adapt your solution to such case?

__Code:__

	class Solution {
	public:

	    //解法1:排序后比较
	    bool isAnagram1(string s, string t) {
	    	//由小到大排序s和t
	        sort(s.begin(), s.end());								//1
	        sort(t.begin(), t.end());
	        //比较排序后的s和t
	        return s == t;
	    }
	    
	    //解法2:使用映射，map为一个int数组，下标分别对应26个字母(只考虑小写)
	    bool isAnagram2(string s, string t) {
	        int map[26] ={0} ; //only lowercase alphabets
	        //memset(map, 0, sizeof(map));
	        
	        //计算每个字符出现次数，并记录到map数组中
	        for (int i=0; i<s.size(); i++) {
	            map[s[i]-'a']++;
	        }
	        //再从map数组中扣除t
	        for (int i=0; i<t.size(); i++) {
	            map[t[i]-'a']--;
	        }
	        
	        //if all alphabets is zero, then they are anagram 
	        for (int i=0; i<sizeof(map)/sizeof(map[0]); i++) {
	            if (map[i]!=0) return false;
	        }
	        return true;
	    } 
	};

##1 std::sort

头文件：`<algorithm>`

格式：

	//default (1)
	template <class RandomAccessIterator> 
		void sort (RandonAccessIterator first, RandomAccessIterator last);
	//custom (2)
	template <class RandomAccessIterator, class Compare>
		void sort (RandomAccessIterator first, RandomAccessIteraotr last, Compare comp);

__Sort elements in range.__

- Sorts the elements in the range [first,last] into ascending order. 
- 默认使用操作符 < 比较元素，也可以自定义比较函数 _comp_，
- Equivalent elements are not guaranteed to keep their original relative order.

__Example__

	// sort algorithm example
	#include <iostream>     // std::cout
	#include <algorithm>    // std::sort
	#include <vector>       // std::vector

	bool myfunction (int i,int j) { return (i<j); }

	struct myclass {
	  bool operator() (int i,int j) { return (i<j);}
	} myobject;

	int main () {
	  int myints[] = {32,71,12,45,26,80,53,33};
	  std::vector<int> myvector (myints, myints+8);               // 32 71 12 45 26 80 53 33

	  // using default comparison (operator <):
	  std::sort (myvector.begin(), myvector.begin()+4);           //(12 32 45 71)26 80 53 33

	  // using function as comp
	  std::sort (myvector.begin()+4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

	  // using object as comp
	  std::sort (myvector.begin(), myvector.end(), myobject);     //(12 26 32 33 45 53 71 80)

	  // print out content:
	  std::cout << "myvector contains:";
	  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
	    std::cout << ' ' << *it;
	  std::cout << '\n';

	  return 0;
	}

	/***********************Output****************************
	myvector contains: 12 26 32 33 45 53 71 80
	*********************************************************/