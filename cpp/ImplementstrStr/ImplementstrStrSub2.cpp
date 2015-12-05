/* Compile Error: Expected '}' at end of input
 * 我觉得问题应该出在string, char 的转换上
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hlen = haystack.size();
        int nlen = needle.size();
        if (hlen==0 || nlen==0) {
            return -1;
        }
        for (int i=0; i<hlen-nlen+1; i++) {
            int j=0;
            for (j=0; j<nlen; j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j==nlen {
                return i;
            }
        }
        return -1;
    }
};