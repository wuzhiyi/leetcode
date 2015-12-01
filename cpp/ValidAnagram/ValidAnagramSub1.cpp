/* 建立一个映射map，然后标记
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return
        vector<int> map(26,0);
        for (int i=0; i<s.size(); i++) {
            map[s[i] - 'a']++;
        }
        for (int j=0; j<s.size(); j++) {
            map[t[j] - 'a']--;
        }
        for (int l=0; l<26; l++) {
            if (map[l] != 0) {
                return false;
            }
        }
        return true;
    }
};