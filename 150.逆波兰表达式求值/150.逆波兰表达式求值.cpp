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
                nums.push(get(c));
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

    int get(string s) {
        int ret = 0, symbol = 1, i = 0;
        if(s[0] == '-'){
            symbol = -1;
            i++;
        }
        for(;i < s.length(); i++) {
            ret = ret * 10 + s[i]-'0';
        }
        return ret*symbol;
    }
};
// @lc code=end

