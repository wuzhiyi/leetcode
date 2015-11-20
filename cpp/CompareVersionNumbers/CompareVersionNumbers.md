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