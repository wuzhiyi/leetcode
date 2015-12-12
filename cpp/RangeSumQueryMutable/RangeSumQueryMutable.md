###Range Sum Query - Immutable
URL: https://leetcode.com/problems/range-sum-query-mutable/</br>
Given an integer array _nums_, find the sum of the elements between indices _i_ and _j_ (_i_ ≤ _j_), inclusive.</br>
The _update_(_i_, _val_) function modifies _nums_ by updating the element at index _i_ to _val_.

####Example:

	Given nums = [1, 3, 5]

	sumRange(0, 2) -> 9
	update(1, 2)
	sumRange(0, 2) -> 8

####Note:
1. The array is only modifiable by the _update_ function.
2. You may assume the number of calls to _update_ and _sumRange_ function is distributed evenly.

####Solution