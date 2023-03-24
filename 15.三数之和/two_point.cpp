// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include<algorithm>
#include "commoncppproblem15.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int> > ans;
    vector<vector<int> > threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++) {
            int j = i+1, k = i+2;
            if(nums[i]+nums[j]+nums[k] > 0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            while(k < n && nums[i]+nums[j]+nums[k] < 0){
                k++;
            }
            if(k == n) k--;
            if(nums[i]+nums[j]+nums[k] == 0) {
                ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                k--;
            }

            while(k!=j) {
                while(k!=j && (nums[i]+nums[j]+nums[k] > 0 || (k+1<n && nums[k] == nums[k+1]))) k--;
                if(nums[i]+nums[j]+nums[k] == 0 && k!=j) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    k--;
                    while(k+1<n && nums[k] == nums[k+1] && k!=j) k--;
                }
                while(k!=j && (nums[i]+nums[j]+nums[k] < 0 || (j-1>i && nums[j] == nums[j-1]))) j++;
                if(nums[i]+nums[j]+nums[k] == 0 && k!=j) {
                    ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    j++;
                    while(j-1>i && nums[j] == nums[j-1] && k!=j) j++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

