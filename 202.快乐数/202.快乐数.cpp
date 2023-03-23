/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while(n != 1) {
            n=f(n);
            if(s.count(n)) break;
            s.insert(n);
        }
        return n == 1;
    }
    int f(int n) {
        int ret = 0;
        while(n) {
            int t = n%10;
            ret += t*t;
            n/=10;
        }
        return ret;
    }
};
// @lc code=end

