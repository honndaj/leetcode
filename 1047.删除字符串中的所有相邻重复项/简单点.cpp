/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        string ss;
        for(char c : s) {
            if(ss.empty()) {
                ss.push_back(c);
            }else {
                if(c == ss.back()) {
                    ss.pop_back();
                }
                else {
                    ss.push_back(c);
                }
            }
        }
        return ss;
    }
};
// @lc code=end

