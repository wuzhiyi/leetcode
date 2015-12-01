class Solution {  
public:  
    vector<int> productExceptSelf(vector<int>& nums) {  
        int n = nums.size();  
        vector<int> right(n+1, 1);  
        for (int i = n-1; i > 0; i--) {  
            right[i] = right[i+1]*nums[i];  
        }  
        int left = 1;  
        vector<int> result;  
        for (int i = 0; i < n; i++) {  
            result.push_back(left*right[i+1]);  
            left *= nums[i];  
        }  
        return result;  
    }  
};  