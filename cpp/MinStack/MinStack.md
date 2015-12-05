###Min Stack
URL: https://leetcode.com/problems/min-stack/</br>
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

- push(x) -- Push element x onto stack.
- pop() -- Removes the element on top of the stack.
- top() -- Get the top element.
- getMin() -- Retrieve the minimum element in the stack.

__Code:__

	class MinStack {
	public:
	    stack<int> stk, minstk;

	    void push(int x) {
	        stk.push(x);
	        if (minstk.empty() or x <= minstk.top()) {
	            minstk.push(x);
	        }
	    }

	    int pop() {
	        int top = stk.top();
	        stk.pop();
	        if (top == minstk.top()) {
	            minstk.pop();
	        }
	        return top;
	    }
	    
	    int top() {
	        return stk.top();
	    }

	    int getMin() {
	        return minstk.top();
	    }
	};