/* 按理应该可以，但是leetcode不能调用strStr(char* h, char* n)
 */

class Solution {
public:
    int strStr(char* haystack, char* needle) {
        int hlen = strlen(haystack);
        int nlen = strlen(needle);
        if (hlen < nlen) return -1;
        
        for (int i=0; i<hlen-nlen; i++) {
            if (!strncmp(haystack+i, needle, nlen)) {
                return i;
            }
        }
        return -1;
    }
};