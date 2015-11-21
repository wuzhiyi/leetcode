###Remove Duplicates from Sorted Array II
URL: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/</br>
Follow up for "Remove Duplicates":</br>
What if duplicates are allowed at most _twice?_</br>
For example,</br>
Given sorted array nums = [1,1,1,2,2,3],</br>
Your function should return length = `5`, with the first five elements of _nums_ being `1`, `1`, `2`, `2` and `3`. It doesn't matter what you leave beyond the new length.

__Code:__

	#include <stdio.h>


	int removeDuplicates(int A[], int n) {
	    if (n<=2) return n;
	    int pos=0;
	    int cnt=1;
	    for (int i=1; i<n; i++){
	        if (A[i] == A[pos]){
	            cnt++;
	            if (cnt==2){
	                A[++pos] = A[i];
	            }
	        }else{
	            cnt=1;
	            A[++pos] = A[i];
	            
	        }
	    } 
	    return pos+1;
	}

	void printfArray(int A[], int n) {
	    printf("{ ");
	    for (int i=0; i<n; i++){
	        printf("%d ", A[i]);
	    }
	    printf("}\n");
	}


	void testSuite(int a[], int n){
	    printfArray(a, n);
	    n = removeDuplicates(a, n);
	    printfArray(a, n);
	    printf("------------------\n");
	}

	#define TEST(a) testSuite(a, sizeof(a)/sizeof(int))
	int main()
	{
	    int a0[] = {1, 2, 3, 4, 5};
	    TEST(a0);
	    int a1[] = {1, 1, 1};
	    TEST(a1);
	    int a2[] = {1, 2, 2};
	    TEST(a2);
	    int a3[] = {1, 1, 2};
	    TEST(a3);
	    int a4[] = {1, 1, 1, 1};
	    TEST(a4);
	    int a5[] = {1, 1, 1, 2};
	    TEST(a5);
	    int a6[] = {1, 2, 2, 2};
	    TEST(a6);
	    int a7[] = {1, 2, 2, 2, 3 };
	    TEST(a7);
	    int a8[] = {1, 2, 2, 2, 3, 3};
	    TEST(a8);
	    int a9[] = {1,1,1,2,2,3};
	    TEST(a9);
	    int a10[] = {1,1,1,2,2,2};
	    TEST(a10);
	    int a11[] = {1,1,1,1,3,3};
	    TEST(a11);
	    return 0;
	}