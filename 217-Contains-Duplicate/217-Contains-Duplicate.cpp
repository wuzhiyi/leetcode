/***********************************************************************
 * 217 Contains Duplicate
 * URL: https://leetcode.com/problems/contains-duplicate/
 * Author: wuzhiyi
 *
 * Given an array of integers, find if the array contains any
 * duplicates. Your function should return true if any value 
 * appears at least twice in the array, and it should return 
 * false if every element is distinct.
 ***********************************************************************/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for (auto item : nums) {
            if (m.find(item) != m.end()) return true;
            m[item] = true;
        }
        return false;
    }
};

