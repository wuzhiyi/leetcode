###Bulls and Cows
URL: https://leetcode.com/problems/bulls-and-cows/</br>
You are playing the following [Bulls and Cows](https://en.wikipedia.org/wiki/Bulls_and_Cows) game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.</br>
For example:

	Secret number:  "1807"
	Friend's guess: "7810"

Hint: `1` bull and `3` cows. (The bull is `8`, the cows are `0`, `1` and `7`.)
Write a function to return a hint according to the secret number and friend's guess, use `A` to indicate the bulls and `B` to indicate the cows. In the above example, your function should return `"1A3B"`.</br>
Please note that both secret number and friend's guess may contain duplicate digits, for example:

	Secret number:  "1123"
	Friend's guess: "0111"

In this case, the 1st `1` in friend's guess is a bull, the 2nd or 3rd `1` is a cow, and your function should return `"1A1B"`.</br>
You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.

__Code:__

	class Solution {
	public:
		/*初始化三个包含10个元素的数组，每个元素表示对应下标出现的次数,
		 *比如appears_in_secret[0]=2,表示在secret中，0出现2次.*/
	    int appears_in_secret[10], appears_in_guess[10], bulls[10];
	    int total_bulls, total_cows;

	    string getHint(string secret, string guess) {
	    	//将secret中的数字信息输入appears_in_secret
	        for(int i = 0; i < secret.size(); i++)
	            appears_in_secret[secret[i] - '0']++;
	        //逐个检测guess，记录下bulls，并记录guess的数字信息
	        for(int i = 0; i < guess.size(); i++) {
	        	//逐个判断，找出bulls.
	             if(secret[i] == guess[i])
	                 bulls[secret[i] - '0']++;
	            //将guess中的数字信息输入appears_in_guess.
	             appears_in_guess[guess[i] - '0']++;
	        }
	        for(int i = 0; i <= 9; i++) {
	        	//累计bulls和
	            total_bulls += bulls[i];
	            //该下标cows的次数＝min(在secret中出现次数,在guess中出现次数)-在bulls中出现次数
	            total_cows += min(appears_in_secret[i], appears_in_guess[i]) - bulls[i];
	        }
	        //返回hint
	        return to_string(total_bulls) + "A" + to_string(total_cows) + "B";		//1
	    }
	};

##1 std::to_string

格式：

	string to_string (int val);
	string to_string (long val);
	string to_string (long long val);
	string to_string (unsigned val);
	string to_string (unsigned long val);
	string to_string (unsigned long long val);
	string to_string (float val);
	string to_string (double val);
	string to_string (long double val);

将数字数值转换成字符串

例子：

	// to_string example
	#include <iostream>   // std::cout
	#include <string>     // std::string, std::to_string

	int main () {
	  std::string pi = "pi is " + std::to_string(3.1415926);
	  std::string perfect = std::to_string(1+2+4+7+14) + " is a perfect number";
	  std::cout << pi << '\n';
	  std::cout << perfect << '\n';
	  return 0;
	}

	/************************output*************************
	pi is 3.141593
	28 is a perfect number
	*******************************************************/
