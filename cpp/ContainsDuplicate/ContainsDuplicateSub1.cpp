/* Hash法
 * 用一个set记录所有已经出现过的数字，若出现冲突，则包含重复元素，
 * 若不冲突，则不包含重复元素。
 * 时间复杂度为O(n)，空间复杂度为O(n).
 */

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        int len=nums.size();
        for(int i=0; i<len; i++){
            if(s.find(nums[i])==s.end()){
                s.insert(nums[i]);
            }else{
                return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    int arr[] = {1, 2, 3, 4, 5, 6, 7,8};
    vector<int> v(arr, arr+8);
    
    if (s.containsDuplicate(v)) {
        cout << "Contains Duplicates" << endl;
    } else {
        cout << "No Duplicates" << endl;
    }
    
    return 0;
}