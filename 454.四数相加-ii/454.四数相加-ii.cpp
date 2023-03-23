/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        vector<int> m1,m2;
        unordered_map<int,int> mp;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[nums1[i]+nums2[j]]++;
                m1.push_back(nums1[i]+nums2[j]);
                m2.push_back(nums3[i]+nums4[j]);
            }
        }
        int ans = 0;
        for(int i = 0; i<n*n; i++) {
            ans += mp[-m2[i]];
        }
        return ans;
    }
};
// @lc code=end

