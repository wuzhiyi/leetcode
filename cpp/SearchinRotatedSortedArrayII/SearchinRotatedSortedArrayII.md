###Search in Rotated Sorted Array II
URL: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/</br>
Follow up for "Search in Rotated Sorted Array":
What if _duplicates_ are allowed?</br>
Would this affect the run-time complexity? How and why?</br>
Write a function to determine if a given target is in the array.

__Code:__

	int binary_search(int A[], int n, int key); 
	int binary_search(int A[], int l, int h, int key); 
	int rotate_search(int A[], int l, int h, int key);

	int search1(int A[], int n, int target);
	int search2(int A[], int n, int target); 

	int search(int A[], int n, int target) {
	    if (random()%2){
	        return search1(A, n, target);
	    }
	    return search2(A, n, target);
	}
	/*
	 *    Using binary search idea, 
	 *    1) Spliting the array to two part, one part should be non-rotated, another one is rotated.
	 *    2) Checking the "key" whether is possible in non-rotated sorted part.
	 *        2.1) if it is, then go to the classcial binary searh.
	 *        2.2) if it not, then keep spliting the rorated part.
	 *
	 */
	int search1(int A[], int n, int key) {
	    if (n<=0) return -1;

	    if (n==1){
	        return (A[0]==key) ? 0 : -1;
	    }
	    int low=0, high=n-1;
	    while( low<=high ){

	        if (A[low] <= A[high] && ( key < A[low] || key > A[high]) ) {
	             return -1;
	        }

	        int mid = low + (high-low)/2;
	        if ( A[mid] == key ) return mid;
	    
	        //the target in non-rotated array
	        if (A[low] < A[mid] && key >= A[low] && key< A[mid]){
	            high = mid - 1;
	            continue;
	        }
	        //the target in non-rotated array
	        if (A[mid] < A[high] && key > A[mid] && key <= A[high] ){
	            low = mid + 1;
	            continue;
	        }
	        //the target in rotated array
	        if (A[low] > A[mid] ){
	            high = mid - 1;
	            continue;
	        }
	        //the target in rotated array
	        if (A[mid] > A[high] ){
	            low = mid + 1;
	            continue;
	        }
	    }
	    return -1;
	}

	int search2(int A[], int n, int target) {
	    if (n<=0) return -1;

	    if (n==1){
	        return A[0]==target?0:-1;
	    }        

	    if ( A[0] < A[n-1] ){
	        return binary_search(A, n, target);
	    }else{
	        return rotate_search(A, 0, n-1, target);
	    }
	}

	int rotate_search(int A[], int low, int high, int key ) {
	    
	    if (low > high){
	        return -1;
	    }
	    if (low==high){
	        return A[low]==key?low:-1;
	    }        
	    
	    int mid = low + (high-low)/2;
	    if ( A[mid] == key ) return mid;

	    if (A[low] < A[mid] && key >= A[low] && key< A[mid]){
	        return binary_search(A, low, mid-1, key);
	    }
	    if (A[mid] < A[high] && key > A[mid] && key <= A[high] ){
	        return binary_search(A, mid+1, high, key);
	    }
	    if (A[low] > A[mid] ){
	        return rotate_search(A, low, mid-1, key);
	    }
	    if (A[mid] > A[high] ){
	        return rotate_search(A, mid+1, high, key);
	    }
	    return -1;
	}

	int binary_search(int A[], int n, int key) {
	    int low = 0;
	    int high = n-1;
	    while (low <= high){
	        int mid = low +(high-low)/2;
	        if (A[mid] == key){
	            return mid;
	        }
	        if ( key> A[mid] ) {
	            low = mid+1;
	        }else{
	            high = mid-1;
	        }
	    }
	    return -1;
	}

	int binary_search(int A[], int low, int high, int key) {
	    //(low+high)/2 could encounter overflow issue
	    int mid = low+(high-low)/2;
	    if (low > high){
	        return -1;
	    }
	    if (A[mid]==key){
	        return mid;
	    }
	    if (key > A[mid]){
	        binary_search(A, mid+1, high, key);
	    }else{
	        binary_search(A, low, mid-1, key);
	    }

	}

	void rotate_array(int a[], int n, int pos){
	    int i, from=0;
	    pos = pos % n;
	    if (n<=0) return;

	    int tmp = a[0];
	    
	    for(int i=0, step=0; step<n && i<pos; step++){
	        int to;
	        if (from-pos < 0) {
	            to = n-pos+from; 
	        }else{
	            to = from-pos;
	        }
	        int t ;
	        t = a[to];
	        a[to] = tmp; 
	        tmp = t;
	        from = to;
	        if ( to == i ){
	            i++;
	            from++;
	            tmp = a[from];
	        }
	    }
	    
	}