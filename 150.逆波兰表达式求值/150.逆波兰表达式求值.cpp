/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(string c : tokens) {
            int a,b;
            if(c == "+" || c == "-" || c == "/" || c == "*") {
                b = nums.top();
                nums.pop();
                a = nums.top();
                nums.pop();
                nums.push(cal(a,b,c));
            }
            else {
                nums.push(stoi(c));
            }
        }
        return nums.top();
    }

    int cal(int a,int b, string op) {
        int ret;
        if(op == "+") ret = a+b;
        if(op == "-") ret = a-b;
        if(op == "/") ret = a/b;
        if(op == "*") ret = a*b;
        return ret; 
    }
};
// @lc code=end

