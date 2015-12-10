class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h_index = 0;
        for (int i=citations.size()-1; i>=0; i--) {
            if (citations[i]>=citations.size()-i && (i-1<0 || citations[i-1]<=citations.size()-i)) h_index = citations.size()-i;
        }
        return h_index;
    }
};