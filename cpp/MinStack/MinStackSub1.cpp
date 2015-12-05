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