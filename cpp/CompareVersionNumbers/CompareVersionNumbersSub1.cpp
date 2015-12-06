class Solution {
public:
    int compareVersion(string version1, string version2) {
        int ret = 0;
        char* ch1 = (char*) version1.c_str();
        char* ch2 = (char*) version2.c_str();
        while (ret==0 && (*ch1 != '\0' || *ch2 != '\0')) {
            long v1 = *ch1 == '\0' ? 0 : strtol(ch1, &ch1, 10);
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