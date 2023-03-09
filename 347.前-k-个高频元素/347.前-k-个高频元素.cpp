/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:

    static bool cmp(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;//value count
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&cmp)> pq(cmp);//value count 
        for(int i = 0; i < n; i++) {
            mp[nums[i]] ++;
        }
        for(pair<int,int> kv : mp) {
            if(pq.size() < k) {
                pq.push(kv);
            }
            else{
                if(pq.top().second < kv.second) {
                    pq.pop();
                    pq.push(kv);
                } 
            }
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};
// @lc code=end

