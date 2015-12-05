###Maximum Gap
URL: https://leetcode.com/problems/maximum-gap/</br>
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Return 0 if the array contains less than 2 elements.

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

__Code:__

	int maximumGap(vector &num) {
	        if (num.empty() || num.size() == 1) return 0;

	        int min = num[0], max = num[0];
	        for (auto n : num) {
	            if (n < min) min = n;
	            if (n > max) max = n;
	        }

	        int gap = (max - min - 1) / (num.size() - 1) + 1;
	        vector bucketMins(num.size() - 1, INT_MAX);
	        vector bucketMaxs(num.size() - 1, INT_MIN);

	        for (auto n : num) {
	            if (n != min && n != max) {
	                int bucketIdx = (n - min) / gap;
	                if (n < bucketMins[bucketIdx]) bucketMins[bucketIdx] = n;
	                if (n > bucketMaxs[bucketIdx]) bucketMaxs[bucketIdx] = n;
	            }
	        }

	        int maxGap = INT_MIN, prev = min;
	        for (int i = 0; i < num.size() - 1; ++i) {
	            if (bucketMins[i] == INT_MAX && bucketMaxs[i] == INT_MIN) continue;
	            if (bucketMins[i] - prev > maxGap) maxGap = bucketMins[i] - prev;
	            prev = bucketMaxs[i];
	        }

	        return std::max(max - prev, maxGap);
	    }