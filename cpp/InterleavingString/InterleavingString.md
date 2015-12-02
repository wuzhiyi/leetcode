###Interleaving String
URL: https://leetcode.com/problems/interleaving-string/</br>
Given _s_1, _s_2, _s_3, find whether _s_3 is formed by the interleaving of _s_1 and _s_2.</br>
For example,</br>
Given:</br>
_s_1 = `"aabcc"`,</br>
_s_2 = `"dbbca"`,

When _s_3 = `"aadbbcbcac"`, return true.</br>
When _s_3 = `"aadbbbaccc"`, return false.

__Code:__

 	bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;  
        bool **f=new bool*[s1.size()+1];
        for(int i=0;i<=s1.size();i++) {
            f[i]=new bool[s2.size()+1];
        }
        f[0][0]=true;
        for(int i = 1; i <= s1.size(); i++) {
            f[i][0]=f[i-1][0] && (s3[i-1] == s1[i-1]);
        }
        for(int i = 1; i <= s2.size(); i++) {
            f[0][i]=f[0][i-1] && (s3[i-1] == s2[i-1]);
        }
        for(int i = 1; i <= s1.size(); i++) {
            for(int j = 1; j <= s2.size(); j++) {
                f[i][j]=(f[i-1][j]&&s1[i-1]==s3[i+j-1])||(f[i][j-1]&&s2[j-1]==s3[i+j-1]);
            }
        }
        return f[s1.size()][s2.size()];
    }