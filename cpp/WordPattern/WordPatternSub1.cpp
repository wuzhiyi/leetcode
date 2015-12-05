class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map1;
        unordered_map<string, char> map2;
        vector<string> vec;
        int count = 0;
        for (int i=0; i<str.size(); i++) {
            if (str[i] == ' ') {
                string tmp = str.substr(count, i-count);
                vec.push_back(tmp);
                count = i+1;
            }
            if (i==str.size() - 1) {
                string tmp = str.substr(count, i-count+1);
                vec.push_back(tmp);
            }
        }
        if (pattern.size() != vec.size()) return false;
        for (int j=0; j<pattern.size(); j++) {
            if (map1.find(pattern[j])==map1.end() && map2.find(vec[j])==map2.end()) {
                map1.insert(make_pair(pattern[j], vec[j]));
                map2.insert(make_pair(vec[j], pattern[j]));
            } else if (map1[pattern[j]]!=vec[j] || map2[vec[j]]!=pattern[j]) {
                return false;
            }
        }
        return true;
    }
};