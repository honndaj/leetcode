// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l, r, ret = 100010;
        bool flag = 0;
        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + nums[i];
        }

        for(int i = 0; i < n; i++) {
            int t = lower_bound(target, i, n, sum);
            if (t == n) continue;
            t = t - i + 1;
            if(t < ret) ret = t;
        }
        return ret == 100010 ? 0 : ret;
    }

    int lower_bound(int target, int start, int n, vector<int>& sum) {
        int l = start, r = n;
        while(l < r) {
            int mid = (l+r)>>1;
            int t = sum[mid + 1] - sum[start];
            if(t >= target) {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};
// @lc code=end

