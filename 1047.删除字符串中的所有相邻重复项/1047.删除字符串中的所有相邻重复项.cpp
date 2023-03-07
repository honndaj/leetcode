/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        deque<char> ss;
        string ans = "";
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            if(!ss.empty()) {
                if(c == ss.back()) {
                    ss.pop_back();
                }
                else {
                    ss.push_back(c);
                }
            }
            else {
                ss.push_back(c);
            }
        }
        while(!ss.empty()) {
            ans.append(1, ss.front());
            ss.pop_front();
        }
        return ans;
    }
};
// @lc code=end

