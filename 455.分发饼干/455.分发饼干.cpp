/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0,j = 0, n = g.size(), m = s.size(),cnt = 0;
        while(i < n && j < m) {//j biscuit
            if(g[i] <= s[j]) {
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
// @lc code=end

