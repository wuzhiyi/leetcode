/* 常规
 * 1. 注意循环结构中的if结构的continue的使用，
 *    因为有可能最后的元素＝val，所以再进入for循环判断一次
 * 2. 另外我的代码其实蛮乱的，思路还不是很清楚
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int n = len;
        if (len<1) {
            return len;
        }
        for (int i=0; i<len;) {
            if (nums[i]==val) {
                cout << "i = " << i << endl;
                nums[i] = nums.back();
                len -= 1;
                nums.pop_back();
                continue;
            }
            i++;
        }
        return len;
    }
};