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

 // 第二遍写 : 
 class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() { min_stk.push(INT_MAX); }

    void push(int x) {
        stk.push(x);
        if (x < min_stk.top())
            min_stk.push(x);
        else
            min_stk.push(min_stk.top());
    }

    void pop() {
        stk.pop();
        min_stk.pop();
    }

    int top() { return stk.top(); }

    int getMin() { return min_stk.top(); }

private:
    stack<int> stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 // link : https://leetcode.cn/problems/bao-han-minhan-shu-de-zhan-lcof/description/?envType=problem-list-v2&envId=XApvNy3p