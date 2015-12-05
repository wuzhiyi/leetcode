class Solution {
public:
    string countAndSay(int n) {
        string pres = "1", news;
        char ch;
        int len, count;
        for (int i=1; i<n; i++) {
            news = "";
            len = pres.size();
            ch = pres[0];
            count = 1;
            for (int j=1; j<len; j++) {
                if (ch == pres[j]) {
                    count++;
                } else {
                    news += count + '0';
                    news += ch;
                    ch = pres[j];
                    count = 1;
                }
            }
            news += count + '0';
            news += ch;
            pres = news;
        }
        return pres;
    }
};