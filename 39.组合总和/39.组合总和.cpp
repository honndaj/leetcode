/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    int sum;
    vector<vector<int>> ans;
    vector<int> t;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        sort(candidates.begin(), candidates.end(), cmp);
        dfs(candidates, target, 0);
        return ans;
    }

    static bool cmp(int a,int b){return a>b;}
    
    void dfs(vector<int>& candidates, int target,int from) {
        if(sum > target) {
            return ;
        }
        if(sum == target) {
            ans.push_back(t);
        }
        for(int i = from; i < candidates.size(); i++) {
            sum+=candidates[i];
            t.push_back(candidates[i]);
            dfs(candidates, target, i);
            sum-=candidates[i];
            t.pop_back();
        }
    }
};
// @lc code=end

