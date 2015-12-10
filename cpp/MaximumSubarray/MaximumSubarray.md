###Maximum Subarray
URL: https://leetcode.com/problems/maximum-subarray/</br>
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.</br>
For example, given the array `[−2,1,−3,4,−1,2,1,−5,4]`,</br>
the contiguous subarray `[4,−1,2,1]` has the largest sum = `6`.

####More practice:
If you have figured out the O(_n_) solution, try coding another solution using the divide and conquer approach, which is more subtle.

__Code:__

	#define INT_MIN     (-2147483647 - 1)

	int maxSubArray1(int A[], int n);
	int maxSubArray2(int A[], int n); 

	int max(int x, int y){
	    return x>y?x:y;
	}

	int maxSubArray1(int A[], int n) {
	    int *sum = new int[n];
	    sum[0] = A[0];
	    int m = A[0]; 
	    for (int i=1; i<n; i++){
	        sum[i] = max(A[i], A[i] + sum[i-1]);
	        m = max(m, sum[i]);
	    }
	    delete[] sum;
	    return m;
	}

	int maxSubArray2(int A[], int n) {
	    int m=INT_MIN;
	    int sum=0;
	    for (int i=0; i<n; i++){
	        sum += A[i];
	        m = max(sum, m);
	        if (sum<0){
	            sum = 0;
	        }
	    }
	    return m;
	}