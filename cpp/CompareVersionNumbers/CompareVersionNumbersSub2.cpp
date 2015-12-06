/* 对开头0的控制没做好
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        for (int i=0; i<version1.size(); i++) {
            if (v1.empty() && version1[i]=='0') continue;
            if (isdigit(version1[i])) {
                v1.push_back(version1[i]-'0');
            }
        }
        for (int i=0; i<version2.size(); i++) {
            if (v2.empty() && version2[i]=='0') continue;
            if (isdigit(version2[i])) {
                v2.push_back(version2[i]-'0');
            }
        }
        for (int j=0; j<version1.size() && j<version2.size(); j++) {
            if (v1[j] > v2[j]) return 1;
            if (v1[j] < v2[j]) return -1;
        }
        return 0;
    }
};