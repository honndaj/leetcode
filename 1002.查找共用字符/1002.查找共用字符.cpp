/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        multiset<int> word[words.size()];
        for(int i = 0; i < words.size(); i++) {
            for(char c : words[i]) {
                word[i].insert(c-'a');
            }
        }
        vector<string> ans;
        for(int i = 0; i<26; i++) {
            int cnt = INT_MAX;
            for(int j = 0; j < words.size(); j++) {
                int t = word[j].count(i);
                if(cnt>t) cnt=t;
            }
            while(cnt--) ans.push_back(string(1,'a'+i));
        }
        return ans;
    }
};
// @lc code=end

