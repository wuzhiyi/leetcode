###Implement strStr()
URL: https://leetcode.com/problems/implement-strstr/</br>
Implement strStr().</br>
Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

__Code:__

	// LeetCode, Implement strStr()
	// 暴力解法，时间复杂度O(N*M)，空间复杂度O(1)
	class Solution {
	public:
		char *strStr(const char *haystack, const char *needle) {
			// if needle is empty return the full string
			if (!*needle) return (char*) haystack;

			const char *p1;
			const char *p2;
			const char *p1_advance = haystack;
			for (p2 = &needle[1]; *p2; ++p2) {
				p1_advance++; // advance p1_advance M-1 times
			}
			for (p1 = haystack; *p1_advance; p1_advance++) {
				char *p1_old = (char*) p1;
				p2 = needle;
				while (*p1 && *p2 && *p1 == *p2) {
				p1++;
				p2++;
				}
				if (!*p2) return p1_old;
				p1 = p1_old + 1;
			}
			return nullptr;
		}
	};

	//KMP
	// LeetCode, Implement strStr()
	// KMP，时间复杂度O(N+M)，空间复杂度O(M)
	class Solution {
	public:
		char *strStr(const char *haystack, const char *needle) {
			int pos = kmp(haystack, needle);
			if (pos == -1) return nullptr;
			else return (char*)haystack + pos;
		}
	private:
		/*
		* @brief 计算部分匹配表，即next 数组.
		**
		@param[in] pattern 模式串
		* @param[out] next next 数组
		* @return 无
		*/
		static void compute_prefix(const char *pattern, int next[]) {
			int i;
			int j = -1;
			const int m = strlen(pattern);

			next[0] = j;
			for (i = 1; i < m; i++) {
				while (j > -1 && pattern[j + 1] != pattern[i]) j = next[j];
				if (pattern[i] == pattern[j + 1]) j++;
				next[i] = j;
			}
		}
		/*
		* @brief KMP 算法.
		**
		@param[in] text 文本
		* @param[in] pattern 模式串
		* @return 成功则返回第一次匹配的位置，失败则返回-1
		*/
		static int kmp(const char *text, const char *pattern) {
			int i;
			int j = -1;
			const int n = strlen(text);
			const int m = strlen(pattern);
			if (n == 0 && m == 0) return 0; /* "","" */
			if (m == 0) return 0; /* "a","" */
			int *next = (int*)malloc(sizeof(int) * m);

			compute_prefix(pattern, next);

			for (i = 0; i < n; i++) {
				while (j > -1 && pattern[j + 1] != text[i]) j = next[j];
				if (text[i] == pattern[j + 1]) j++;
				if (j == m - 1) {
					free(next);
					return i-j;
				}
			}

			free(next);
			return -1;
		}

		/* 网上公认比较好的解法
		 * Java
		 */
		public int strStr(String haystack, String needle) {
			// 从haystack开始
			for (int i = 0;; i++) {
				// 匹配needle的字符
				for (int j = 0;; j++) {
					/* 如果needle和j一样长，则直接返回i(当前匹配的起始位置)
					 * ，因为已经匹配成功了
					 */
					if (j == needle.length())
						return i;
					/* 如果i+j为当前haystack的长度，则表明已经走完heystack
					 * 所有的字符，并且没有匹配成功(注意如果最后一个字符正好匹
					 * 配成功，则在上面一个判断就会返回)
					 */
					if (i + j == haystack.length())
						return -1;
					/* 如果当前needle和haystack的字符相同的话(因为每次不成功
					 * 匹配不成功，则i移动1位，而j又重新从0开始，所以haystack
					 * 的当前位置是i+j)
					 */
					if (needle.charAt(j) != haystack.charAt(i + j))
						break;
				}
			}
}
	};