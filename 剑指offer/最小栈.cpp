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