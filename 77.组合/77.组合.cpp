// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem77.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,0, 0);
        return ans;
    }

    void dfs(int n, int k, int dep, int now) {
        if(n-now < k -dep) {
            return ;
        }
        if(dep == k) {
            ans.push_back(temp);
            return ;
        }
        for(int i = now + 1; i <= n; i++) {
            temp.push_back(i);
            dfs(n, k, dep+1, i);
            temp.pop_back();
        }
    }
};
// @lc code=end

