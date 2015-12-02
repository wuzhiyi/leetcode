###Find Median from Data Stream
URL: https://leetcode.com/problems/find-median-from-data-stream/</br>
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
####Examples: 
`[2,3,4]` , the median is `3`</br>
`[2,3]`, the median is `(2 + 3) / 2 = 2.5`</br>

Design a data structure that supports the following two operations:

- void addNum(int num) - Add a integer number from the data stream to the data structure.
- double findMedian() - Return the median of all elements so far.

For example:</br>

	add(1)
	add(2)
	findMedian() -> 1.5
	add(3) 
	findMedian() -> 2


__Code:__

	public class Solution {
	    public int[] medianII(int[] nums) {
	        // write your code here
	        if(nums.length <= 1) return nums;
	        int[] res = new int[nums.length];
	        PriorityQueue<Integer> minheap = new PriorityQueue<Integer>();
	        PriorityQueue<Integer> maxheap = new PriorityQueue<Integer>(11, new Comparator<Integer>(){
	            public int compare(Integer arg0, Integer arg1) {
	                return arg1 - arg0;
	            }
	        });
	        // 将前两个元素先加入堆中
	        minheap.offer(Math.max(nums[0], nums[1]));
	        maxheap.offer(Math.min(nums[0], nums[1]));
	        res[0] = res[1] = Math.min(nums[0], nums[1]);
	        for(int i = 2; i < nums.length; i++){
	            int mintop = minheap.peek();
	            int maxtop = maxheap.peek();
	            int curr = nums[i];
	            // 新数在较小的一半中
	            if (curr < maxtop){
	                if (maxheap.size() <= minheap.size()){
	                    maxheap.offer(curr);
	                } else {
	                    minheap.offer(maxheap.poll());
	                    maxheap.offer(curr);
	                }
	            // 新数在中间
	            } else if (curr >= maxtop && curr <= mintop){
	                if (maxheap.size() <= minheap.size()){
	                    maxheap.offer(curr);
	                } else {
	                    minheap.offer(curr);
	                }
	            // 新数在较大的一半中
	            } else {
	                if(minheap.size() <= maxheap.size()){
	                    minheap.offer(curr);
	                } else {
	                    maxheap.offer(minheap.poll());
	                    minheap.offer(curr);
	                }
	            }
	            if (maxheap.size() == minheap.size()){
	                res[i] = (maxheap.peek() + minheap.peek()) / 2;
	            } else if (maxheap.size() > minheap.size()){
	                res[i] = maxheap.peek();
	            } else {
	                res[i] = minheap.peek();
	            }
	        }
	        return res;
	    }
	}
