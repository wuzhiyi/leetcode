###228 Summary Ranges
URL: https://leetcode.com/problems/summary-ranges/</br>
Given a sorted integer array without duplicates, return the summary of its ranges.</br>
For example, given `[0,1,2,4,5,7]`, return `["0->2","4->5","7"]`.

__Code:__

	class Solution {
	public:
	    string makeRange(int start, int end) {
	        ostringstream oss;								//1
	        if (start != end) {
	            oss << start << "->" << end;
	        } else {
	            oss << start;
	        }
	        return oss.str();
	    }
	    
	    vector<string> summaryRanges(vector<int>& nums) {
	        vector<string> result;
	        int len = nums.size();
	        if (len == 0) return result;
	        
	        // we have two pointer for range-starter and range-ender
	        int start=nums[0], end=nums[0];

	        for (int i=1; i<len; i++) {
	            // if it is continous number, move the end pointer;
	            if (nums[i] == end + 1) {
	                end = nums[i];
	                continue;
	            }
	            
	            //if the number is not continous, push the range into result
	            //and reset the start and end pointer
	            result.push_back(makeRange(start, end));
	            start = end = nums[i];
	        
	        }
	        
	        //for the last range
	        result.push_back(makeRange(start, end)); 
	        
	        return result;
	    }
	};

###1 ostringstream

istringstream, ostringstream, stringstream 类介绍：

####C++ 的输入输出分为三种：

1. 基于控制台的 I/O
头文件：`iostream`</br>
类型：

- `iostream` 	从__流__中读取.
- `ostream` 	写到__流__中去.
- `iostream` 	对__流__进行读写，从 istream 和 ostream 派生.

2. 基于文件的 I/O
头文件：`fstream`</br>
类型：

- `ifstream` 	从__文件__中读取，由 istream 派生.
- `ofstream`	写到__文件__中去，由 ostream 派生.
- `fstream` 	对__文件__进行读写，由 iostream 派生.

3. 基于字符串的 I/O
头文件：`sstream`</br>
类型：

- `istringstream`	从 __string__ 对象中读取，由 istream 派生.
- `ostringstream`	写到 __string__ 对象中去，由 ostream 派生.
- `stringstream`	对 __string__ 对象进行读写，由 iostream 派生.

####作用

- `istringstream` 类用于执行 C++ 风格的字符串流的__输入__操作.
- `ostringstream` 类用于执行 C++ 风格的字符串流的__输出__操作.
- `stringstream` 类可以同时支持 C++ 风格的串流的__输入输出__操作.