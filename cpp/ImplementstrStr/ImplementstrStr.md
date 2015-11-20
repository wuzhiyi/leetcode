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
	};