class MinStack {
private:
    stack<int> stk;
    // 这个最小栈一直存的是 stk 中的最小值
    // ![](https://assets.leetcode-cn.com/solution-static/155/155_fig1.gif)
    stack<int> min_stk;

public:
    MinStack() { min_stk.push(INT_MAX); }

    void push(int val) {
        stk.push(val);
        min_stk.push(min(
            val, min_stk.top())); // push 进去的是当前值和 min_stk 中的较小值
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min_stk.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */