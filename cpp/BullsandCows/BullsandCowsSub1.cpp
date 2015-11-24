/* Hash法
 * 三个整型数组，对应secret，guess，bulls数字和出现次数
 * 然后两个标记total_bulls, total_cows,另外leetcode编译有点要注意初始化要先赋值为0.
 * 输出时注意total_cows
 */

#include <iostream>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int app_in_secret[10]={},
        app_in_guess[10]={},
        bulls[10]={};
        int tot_bulls = 0;
        int tot_cows = 0;
        for (int i=0; i<secret.size(); i++) {
            app_in_secret[secret[i]-'0']++;
        }
        for (int j=0; j<guess.size(); j++) {
            app_in_guess[guess[j]-'0']++;
            if (secret[j] == guess[j]) {
                bulls[secret[j]-'0']++;
            }
        }
        for (int l=0; l<10; l++) {
            tot_bulls += bulls[l];
            tot_cows += min(app_in_secret[l], app_in_guess[l])-bulls[l];
        }
        return to_string(tot_bulls) + 'A' + to_string(tot_cows) + 'B';
    }
    
    
};

int main()
{
    Solution s;
    string secret = "2907";
    string guess = "7810";
    string ans = s.getHint(secret, guess);
    cout << secret << "\t" << guess << "\nhint=" << ans << endl;
    //int arr[] = {0,1,0,3,12};
    //vector<int> arr_vec(&arr[0], &arr[0]+sizeof(arr)/sizeof(int));
    //cout << s.majorityElement(arr_vec) << endl;
    /*
    for (int i=0; i<arr_vec.size(); i++) {
        cout<<arr_vec[i]<<",";
    }
     */
    
    return 0;
}