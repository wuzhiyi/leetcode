###Count and Say
URL: https://leetcode.com/problems/count-and-say/</br>
The count-and-say sequence is the sequence of integers beginning as follows:</br>
`1, 11, 21, 1211, 111221, ...`</br>
`1` is read off as `"one 1"` or `11`.</br>
`11` is read off as `"two 1s"` or `21`.</br>
`21` is read off as `"one 2` then `one 1"` or `1211`.</br>
Given an integer _n_, generate the _n_th sequence.</br>
Note: The sequence of integers will be represented as a string.

__Code:__

	#include <stdlib.h>
	#include <iostream>
	#include <sstream>
	#include <string>
	#include <vector>
	using namespace std;

	string vecToStr(vector<int> v) {
	    stringstream ss;
	    for (int i=0; i<v.size(); i++) {
	        ss << v[i]; 
	    }
	    return ss.str();
	}

	vector<int> getNext(vector<int>& v) {
	    int cnt=0;
	    int val=0;
	    vector<int> ret;
	    for(int i=0; i<v.size(); i++){
	        if (i==0){
	            val = v[i];
	            cnt = 1;
	            continue;
	        }
	        if (v[i] == val){
	            cnt++;
	        }else{
	            ret.push_back(cnt); 
	            ret.push_back(val); 
	            val = v[i];
	            cnt = 1;
	        }
	    }
	    if (cnt>0 && val>0){
	        ret.push_back(cnt); 
	        ret.push_back(val); 
	    }
	    return ret;
	}
	    

	string countAndSay(int n) {
	    if (n<=0) return "";
	    if (n==1) return "1";

	    string s;
	    vector<int> v;
	    v.push_back(1);
	    for(int i=2; i<=n; i++){
	       v = getNext(v);
	       //s = s + ", " +vecToStr(v);
	    }
	    s = vecToStr(v);
	    return s;
	}


	int main(int argc, char** argv)
	{
	    int n = 4;
	    if (argc>1){
	        n = atoi(argv[1]);
	    }
	    cout << countAndSay(n) << endl;
	    
	    return 0;
	}