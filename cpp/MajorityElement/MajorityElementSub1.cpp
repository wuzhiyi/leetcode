/* 其实cnt的意思不是maj出现的次数，而是一个比较标记
 * 标示这个元素出现的次数与其他元素出现次数比较的结果
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorityIndex = 0;
        for(int cnt = 1, i = 1; i < nums.size(); i++)
        {
            nums[majorityIndex] == nums[i] ? cnt++ : cnt--;
            if(cnt == 0)
            {
                cnt = 1;
                majorityIndex = i;
            }
        }
        return nums[majorityIndex];
    }
};