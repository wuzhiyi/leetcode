/* 两个映射maps, mapt，交叉映射
 * 关键在于maps储存t，mapt储存s
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;
        int MAX=256;
        char maps[MAX]={0}, mapt[MAX]={0};
        for (int i=0; i<s.size(); i++) {
            if (maps[s[i]]==0 && mapt[t[i]]==0) {
                maps[s[i]]=t[i];
                mapt[t[i]]=s[i];
                continue;
            }
            if (maps[s[i]]==t[i] && mapt[t[i]]==s[i]) {
                continue;
            }
            return false;
        }
        return true;
    }
};