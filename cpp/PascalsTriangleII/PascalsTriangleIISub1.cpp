/* 两层循环结构
 * 两层循环结构的方向是相反的
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> arr(rowIndex+1, 0);
        arr[0]=1;
        for (int i=0; i<rowIndex; i++) {
            for (int j=i+1; j>0; j--) {
                arr[j] += arr[j-1];
            }
        }
        
        return arr;
    }
    
};