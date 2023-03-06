/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
private:
    stack<int> tail, head;
public:
    MyQueue() {
    }
    
    void push(int x) {
        tail.push(x);
    }
    
    int pop() {
        int ret = -1;
        if(head.empty()) {
            while(!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
        ret = head.top();
        head.pop();
        return ret;
    }
    
    int peek() {
        if(head.empty()) {
            while(!tail.empty()) {
                head.push(tail.top());
                tail.pop();
            }
        }
        return head.top();
    }
    
    bool empty() {
        return (head.empty() && tail.empty()) ? 1 : 0; 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

