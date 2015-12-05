/* 类中初始化两个数组，在调用NumArray时存储nums每个元素及累积和
 * 调用sumRange时就根据i, j返回结果
 */

class NumArray {
public:
    vector<int> sumArray;
    vector<int> array;
    NumArray(vector<int> &nums) {
        int sum = 0;
        for (int i=0; i<nums.size(); i++) {
            array.push_back(nums[i]);
            sum += nums[i];
            sumArray.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        return sumArray[j]-sumArray[i]+array[i];
    }
};