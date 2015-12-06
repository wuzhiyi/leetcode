/* 二分查找
 * Time Limit Exceeded
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low=1, high=n;
        while (low<=high) {
            int mid = low + (high-low)/2;
            if (!isBadVersion(mid-1) && isBadVersion(mid)) {
                return mid;
            }
            if (isBadVersion(mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    
};