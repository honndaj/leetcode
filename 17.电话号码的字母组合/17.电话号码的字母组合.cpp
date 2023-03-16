/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<char> mp[10];
    string t;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};
        t = "";
        if(digits.size()) dfs(digits, 0);
        return ans;
    }

    void dfs(string digits, int dep) {
        if(dep == digits.length()) {
            ans.push_back(t);
            return ;
        }
        int x = digits[dep]-'0';
        for(int i = 0; i < mp[x].size(); i++) {
            t.push_back(mp[x][i]);
            dfs(digits, dep+1);
            t.pop_back();
        }
    }
};
// @lc code=end

