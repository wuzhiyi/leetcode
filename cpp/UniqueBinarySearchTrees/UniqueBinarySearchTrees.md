###Unique Binary Search Trees
URL: https://leetcode.com/problems/unique-binary-search-trees/</br>
Given n, how many structurally unique __BST's__ (binary search trees) that store values 1..._n_?</br>
For example,</br>
Given n = 3, there are a total of 5 unique BST's.

	   1         3     3      2      1
	    \       /     /      / \      \
	     3     2     1      1   3      2
	    /     /       \                 \
	   2     1         2                 3

__Code:__

	int numTrees(int n) {
	    return numTrees1(n);
	}

	int numTrees1(int n) {
	    int *cnt = (int*)malloc((n+1)*sizeof(int));
	    memset(cnt, 0, (n+1)*sizeof(int));
	    cnt[0] = 1;
	    cnt[1] = 1;
	    
	    for (int i=2; i<=n; i++){
	        for(int j=0; j<i; j++){
	           cnt[i] += cnt[j]*cnt[i-j-1];
	        }
	    }
	    int sum = cnt[n];
	    free(cnt);
	    return sum;
	}



	int numTrees2(int n) {
	    if (n<=0) return 0;
	    if (n == 1 ) return 1;
	    int sum=0;
	    for (int i=1; i<=n; i++){
	        if (i==1||i==n){
	            sum += numTrees(n-1);
	        }else{
	            sum += (numTrees(i-1) * numTrees(n-i));
	        }
	    }
	    return sum;
	}