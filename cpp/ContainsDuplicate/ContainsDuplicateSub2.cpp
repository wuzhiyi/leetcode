/* 排序法
 * 现将数组排序，然后扫描一次数组，若出现相邻的两个数相同，
 * 则包含重复元素，否则没有。此方法时间复杂度为O（nlogn），
 * 空间复杂度为O（1)(取决于排序方法).
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len=nums.size();
        //i=1,考虑nums只有一个元素的情况
        for(int i=1; i<len; i++){
            if(nums[i-1]==nums[i]){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int arr[] = {1, 2, 3, 1, 5, 6, 7,8};
    vector<int> v(arr, arr+8);
    
    if (s.containsDuplicate(v)) {
        cout << "Contains Duplicates" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }
    
    return 0;
}