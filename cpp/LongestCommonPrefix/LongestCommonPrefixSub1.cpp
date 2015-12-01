class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if (strs.size()<=0) return result;
        for (int i=0; i<strs[0].size(); i++) {
            char ch = strs[0][i];
            for (int j=0; j<strs.size(); j++) {
                if (ch != strs[j][i]) return result;
            }
            result.push_back(ch);
        }
        return result;
    }
};