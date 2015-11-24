/* 唯一的技巧是从尾往前依次赋值
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i,j,k;
        for (i=m-1,j=n-1,k=m+n-1; k>=0; --k) {
            if (i>=0 && (j<0 || nums1[i]>nums2[j])) {
                nums1[k] = nums1[i--];
            } else {
                nums1[k] = nums2[j--];
            }
        }
    }
};