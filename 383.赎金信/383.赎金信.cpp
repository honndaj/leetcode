/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> word(26,0);
        for(char c : magazine) {
            word[c-'a']++;
        }
        for(char c : ransomNote) {
            word[c-'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(word[i] < 0) return 0;
        }
        return 1;
    }
};
// @lc code=end

