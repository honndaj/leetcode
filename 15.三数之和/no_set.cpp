// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        vector<vector<int> > ans;
        set<vector<int> > s;

        sort(nums.begin(), nums.end());
        if(nums[0] > 0) return ans;
        for(int i = 0; i< n; i++) {
            mp[nums[i]] = i;
        }
        
        for(int i = 0; i<n; i++) {
            if(i > 0 && nums[i-1] == nums[i]) continue;
            for(int j = i+1; j< n;j++) {
                if(j>i+1 && nums[j] == nums[j-1]) continue;
                int pos = mp[-nums[i]-nums[j]];
                if(pos > j) {
                    ans.push_back(vector<int>{nums[i],nums[j],nums[pos]});
                }
            }
        }
        return ans;
    }

};
// @lc code=end

