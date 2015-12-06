###Compare Version Numbers
URL: https://leetcode.com/problems/compare-version-numbers/</br>
Compare two version numbers _version1_ and _version2_.</br>
If _version1_ > _version2_ return 1, if version1 < version2 return -1, otherwise return 0.</br>
You may assume that the version strings are non-empty and contain only digits and the `.` character.</br>
The `.` character does not represent a decimal point and is used to separate number sequences.</br>
For instance, `2.5` is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.</br>
Here is an example of version numbers ordering:

	0.1 < 1.1 < 1.2 < 13.37

__Code:__

	class Solution {
	    public:
	        vector<int> &split(const string &s, char delim, vector<int> &elems) {
	            stringstream ss(s);
	            string item;
	            while (getline(ss, item, delim)) {
	                elems.push_back(atoi(item.c_str()));
	            }
	            return elems;
	        }


	        vector<int> split(const string &s, char delim) {
	            vector<int> elems;
	            split(s, delim, elems);
	            return elems;
	        }

	        void rightTrimZero(vector<int> &v){
	            while (v.back() == 0){
	                v.pop_back();
	            }
	        }

	        int compareVersion(string version1, string version2) {

	            //split the version by delimer '.'
	            vector<int> ver1 = split(version1, '.');
	            vector<int> ver2 = split(version2, '.');

	            //remove the right Zeros
	            rightTrimZero(ver1);
	            rightTrimZero(ver2);

	            //compare two versions 
	            for (int i=0; i<ver1.size() && i < ver2.size(); i++) {
	                if (ver1[i] < ver2[i]){
	                    return -1;
	                }else if(ver1[i] > ver2[i]){
	                    return 1;
	                }
	            }

	            //if the above for-loop is not returned, which means they are equal so far
	            //then check the length.
	            if (ver1.size() > ver2.size()) {
	                return 1;
	            }else if (ver1.size() < ver2.size()) {
	                return -1;
	            }

	            return 0;

	        }

	};

####解法2

	class Solution {
	public:
	    int compareVersion(string version1, string version2) {
	        int ret = 0;
	        char* ch1 = (char*) version1.c_str();
	        char* ch2 = (char*) version2.c_str();
	        while (ret==0 && (*ch1 != '\0' || *ch2 != '\0')) {
	            long v1 = *ch1 == '\0' ? 0 : strtol(ch1, &ch1, 10);		//1
	            long v2 = *ch2 == '\0' ? 0 : strtol(ch2, &ch2, 10);
	            if (v1 > v2) {
	                ret = 1;
	            } else if (v1 < v2) {
	                ret = -1;
	            } else {
	                if (*ch1 != '\0') ch1++;
	                if (*ch2 != '\0') ch2++;
	            }
	        }
	        return ret;
	    }
	};

###strtol

long int strtol(const char *nptr,char **endptr,int base);

将参数 nptr 字符串根据参数 base 来转换成长整型数。base 指示进制数，如 10 表示是十进制。strtol 扫描会跳过前面的空格字符，直到遇到数字或正负符号开始，再遇到非数字或者字符串结束符 ”\0“ 结束转换，并将结果返回。

endptr 是一个传出参数，函数返回时指向后面未被识别的第一个字符。例如 char *pos; strtol("123abc", &pos, 10);，strtol 返回 123，pos 指向字符串中的字母 a。如果字符串开头没有可识别的整数，例如 char *pos; strtol("ABCabc", &pos, 10);，则 strtol 返回 0，pos 指向字符串开头，可以据此判断这种出错的情况，而这是 atoi 处理不了的。

###CString和String区别

CString是以空字符null结束的字符数组。string类是标准库的类，并不是内置类型，标准库就像是我们自己定义的类差不多的，string类型对象没有标配'\0'结尾的。不过String可以实现自动转换。