class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > vv;
        if (n<=0) return vv;
        //Initilize 2d matrix
        for (int i=0; i<n; i++) {
            vector<int> v(n);
            vv.push_back(v);
        }
        int cnt = 1;
        for (int r=0,c=0; r<(n+1)/2 && c<(n+1)/2; r++,c++) {
            for (int i=c; i<n-c; i++) vv[r][i] = cnt++;
            for (int i=r+1; i<n-r; i++) vv[i][n-c-1] = cnt++;
            for (int i=n-c-2; n-r-1>r && i>=c; i--) vv[n-r-1][i] = cnt++;
            //注意判断条件是i>r, 而不是i>=r.
            for (int i=n-r-2; n-c-1>c && i>r; i--) vv[i][c] = cnt++;
        }
        return vv;
    }
};