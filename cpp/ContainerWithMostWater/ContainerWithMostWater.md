###Container With Most Water
URL: https://leetcode.com/problems/container-with-most-water/</br>
Given n non-negative integers _a_1, _a_2, ..., _a_n, where each represents a point at coordinate (_i_, _a_i). n vertical lines are drawn such that the two endpoints of line i is at (_i_, _a_i) and (_i_, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.

__Reference:__

http://www.cnblogs.com/tenosdoit/p/3812880.html

__Code:__

	//解法1
	class Solution {
	    struct Node
	    {
	        int height;
	        int index;
	        Node(int h, int i):height(h),index(i){}
	        Node(){}
	        bool operator < (const Node &a)const
	        {
	            return height < a.height;
	        }
	    };
	public:
	    int maxArea(vector<int> &height) {
	        int res = 0, n = height.size();
	        if(n <= 1)return 0;
	        vector<Node>vec(n);
	        for(int i = 0; i < n; i++)
	        {
	            vec[i].index = i;
	            vec[i].height = height[i];
	        }
	        sort(vec.begin(), vec.end());
	         
	        int start = vec[n-1].index, end = start;//记录已经处理完的height的原始位置的左右端点
	        for(int i = n-2; i >= 0 ; i--)
	        {
	            start = min(start, vec[i].index);
	            end = max(end, vec[i].index);
	            res = max(res, max(vec[i].height*(vec[i].index - start), vec[i].height*(end - vec[i].index)));
	        }
	        return res;
	    }
	};

	//Solution2
	class Solution {
	public:
	    int maxArea(vector<int> &height) {
	        int res = 0, n = height.size();
	        int left = 0, right = n-1;
	        while(left < right)
	        {
	            res = max(res, (right-left)*min(height[left], height[right]));
	            if(height[left] < height[right])
	                left++;
	            else right--;
	        }
	        return res;
	    }
	};

	//Solution3
	class Solution {
	public:
	    int trap(int A[], int n) {
	        int res = 0;
	        vector<int>rightMax(n);//柱子右边最大的柱子高度
	        int maxv = 0;
	        for(int i = n-1; i >= 0; i--)
	        {
	            rightMax[i] = maxv;
	            maxv < A[i] ? maxv = A[i] : maxv;
	        }
	        maxv = 0;
	        int conHeight;
	        for(int i = 0; i < n; i++)
	        {//此时maxv为柱子i左边最大的柱子高度
	            conHeight = min(maxv, rightMax[i]);
	            if(conHeight > A[i])
	                res += conHeight - A[i];
	            maxv < A[i] ? maxv = A[i] : maxv;
	        }
	        return res;
	    }
	};

	//Solution4
	class Solution {
	public:
	    int trap(int A[], int n) {
	        int maxHeight = 0, maxIdx = 0;
	        for(int i = 0; i < n; i++)//求最大高度
	            if(A[i] > maxHeight)
	            {
	                maxHeight = A[i];
	                maxIdx = i;
	            }
	        int height = 0;
	        int pillarArea = 0;//柱子面积
	        int totalArea = 0;//总面积
	        for(int i = 0; i < maxIdx; i++)
	        {
	            if(A[i] > height)
	            {
	                totalArea += (A[i] - height)*(maxIdx - i);
	                height = A[i];
	            }
	            pillarArea += A[i];
	        }
	        height = 0;
	        for(int i = n-1; i > maxIdx; i--)
	        {
	            if(A[i] > height)
	            {
	                totalArea += (A[i] - height)*(i - maxIdx);
	                height = A[i];
	            }
	            pillarArea += A[i];
	        }
	        return totalArea - pillarArea;
	    }
	};

	//Solution5
	class Solution {
	public:
	    int trap(int A[], int n) {
	        int left = 0, right = n-1;
	        int totalArea = 0, pillarArea = 0, height = 0;
	        while(left <= right)
	        {
	            if(A[left] < A[right])
	            {
	                if(A[left] > height)
	                {
	                    totalArea += (A[left]-height)*(right - left + 1);
	                    height = A[left];
	                }
	                pillarArea += A[left];
	                left++;
	            }
	            else
	            {
	                if(A[right] > height)
	                {
	                    totalArea += (A[right]-height)*(right - left + 1);
	                    height = A[right];
	                }
	                pillarArea += A[right];
	                right--;
	            }
	        }
	        return totalArea - pillarArea;
	    }
	};