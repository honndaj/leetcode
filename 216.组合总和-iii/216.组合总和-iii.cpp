/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    int sum;

    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        dfs(k,n,1);
        return ans;
    }
    
    void dfs(int k,int n,int cur) {
        if(t.size() == k) {
            if(sum == n) ans.push_back(t);
            return ;
        }
        if(cur > 9 || sum >= n) {
            return ;
        }
        t.push_back(cur);
        sum+=cur;
        dfs(k,n,cur+1);
        t.pop_back();
        sum-=cur;

        dfs(k,n,cur+1);
    }
};
// @lc code=end

