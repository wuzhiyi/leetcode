###Additive Number
URL: https://leetcode.com/problems/additive-number/</br>
Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain __at least__ three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

For example:
`"112358"` is an additive number because the digits can form an additive sequence: `1, 1, 2, 3, 5, 8`.

	1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

`"199100199"` is also an additive number, the additive sequence is: `1, 99, 100, 199`.

	1 + 99 = 100, 99 + 100 = 199

__Note:__ Numbers in the additive sequence __cannot__ have leading zeros, so sequence `1, 2, 03` or `1, 02, 3` is invalid.

Given a string containing only digits `'0'-'9'`, write a function to determine if it's an additive number.

####Follow up:
How would you handle overflow for very large input integers?

__Code:__