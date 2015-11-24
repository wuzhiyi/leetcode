class Solution {
public:
    string makeRange(int start, int end) {
        ostringstream oss;
        if (start != end) {
            oss << start << "->" << end;
        } else {
            oss << start;
        }
        return oss.str();
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int len = nums.size();
        if (len == 0) {
            return result;
        }
        //区间头尾标记
        int start = nums[0], end = nums[0];
        
        for (int i=1; i<len; i++) {
            if (nums[i] == end+1) {
                end = nums[i];
                continue;
            }
            result.push_back(makeRange(start, end));
            start = end = nums[i];
        }
        //注意这行搂底
        result.push_back(makeRange(start, end));
        return result;
    }
};