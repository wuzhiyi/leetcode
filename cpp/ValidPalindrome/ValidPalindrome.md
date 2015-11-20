###Valid Palindrome
URL: https://leetcode.com/problems/valid-palindrome/</br>
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.</br>

For example,</br>
`"A man, a plan, a canal: Panama"` is a palindrome.
`"race a car"` is ___not___ a palindrome.

####Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.</br>
For the purpose of this problem, we define empty string as valid palindrome.

__Code:__

	class Solution {
	public:
	    bool isPalindrome(string s) {
	        s = removeNoise(s);
	        for(int i=0; i<s.size()/2; i++){
	            if (s[i]!= s[s.size()-i-1]){
	                return false;
	            }
	        }
	        return true;
	    }
	    
	    string removeNoise(string& s){
	        string d;
	        for(int i=0; i<s.size(); i++){
	            if(::isalpha(s[i]) || ::isdigit(s[i])){
	                d.push_back(::tolower(s[i]));
	            }
	        }
	        return d;
	    }
	};