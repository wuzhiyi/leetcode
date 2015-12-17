###Maximum Product Subarray
URL: https://leetcode.com/problems/maximum-product-of-word-lengths/</br>
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

####Example 1:
Given `["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]`</br>
Return `16`</br>
The two words can be `"abcw", "xtfn"`.</br>

####Example 2:
Given `["a", "ab", "abc", "d", "cd", "bcd", "abcd"]`</br>
Return `4`</br>
The two words can be `"ab", "cd"`.

####Example 3:
Given `["a", "aa", "aaa", "aaaa"]`</br>
Return `0`</br>
No such pair of words.

####Follow up:
Could you do better than O(n^2), where n is the number of words?

__Code:__
