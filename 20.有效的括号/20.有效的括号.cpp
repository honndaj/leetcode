/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<int> S;
        map<char ,char> mp;
        bool flag = 1;
        mp['('] =')';
        mp['['] =']';
        mp['{'] = '}'; 
        for(auto c : s) {
            if(c == '(' || c == '{' || c == '['){
                S.push(c);
            }
            else {
                if(S.empty() || mp[S.top()] != c) {
                    flag = 0;
                    break;
                }
                S.pop();
            }
        }
        if(!S.empty()) flag = 0;
        return flag;
    }
};
// @lc code=end

