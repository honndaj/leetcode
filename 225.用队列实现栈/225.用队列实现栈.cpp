/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
class MyStack {
private:
    queue<int> q, tq;

public:
    MyStack() {

    }
    
    void push(int x) {
        while(!q.empty()) {
            tq.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!tq.empty()) {
            q.push(tq.front());
            tq.pop();
        }
    }
    
    int pop() {
        int ret = q.front();
        q.pop();
        return ret;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

