###Next Permutation
URL: https://leetcode.com/problems/next-permutation/</br>
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.</br>
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).</br>
The replacement must be in-place, do not allocate extra memory.</br>
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.</br>
`1,2,3` → `1,3,2`</br>
`3,2,1` → `1,2,3`</br>
`1,1,5` → `1,5,1`</br>

__Code:__

	void nextPermutation(vector<int> &num) {

	    if(num.size()<=1) return;

	    for(int i=num.size()-1; i>0; i--) {
	        if (num[i-1] < num[i]){
	            int j = num.size()-1;
	            while( num[i-1] >= num[j]) {
	                //pass;
	                j--;
	            }
	            int tmp = num[j];
	            num[j] = num[i-1];
	            num[i-1] = tmp;
	            //sort works as well
	            //sort(num.begin()+i, num.end()); 
	            reverse(num.begin()+i, num.end()); 
	            return; 
	        }
	        //edge case
	        if (i == 1 ){
	            //sort works as well
	            reverse(num.begin(), num.end());
	            return;
	        }
	    }

	}
