/* Compile Error
 * string与char的区别与使用
 */

class Solution {
public:
    int myAtoi(const char *str) {
        if (str==NULL || *str=='\0') {
            return 0;
        }
        int ret=0;
        for (; isspace(*str); str++);
        bool neg=false;
        if (*str=='-' || *str=='+') {
            neg = (*str=='-');
            str++;
        }
        for (; isdigit(*str); str++) {
            int digit = (*str-'0');
            if (neg) {
                if (-ret<(INT_MIN+digit)/10) {
                    return INT_MIN;
                }
            } else {
                if (ret >(INT_MAX-digit)/10) {
                    return INT_MAX;
                }
            }
            ret = 10*ret + digit;
        }
        return neg ? -ret : ret;
    }
};