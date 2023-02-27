// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int index;
    int value;
}bean;

class Solution {
public:

    bool static cmp(bean a, bean b) {
        return a.value < b.value;
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        vector<bean> beans(n);
        for(int i = 0; i < n; i++){
            beans[i].index = i;
            beans[i].value = nums[i];
        }
        sort(beans.begin(), beans.end(), cmp);

        for(int i = 0; i < n; i++) {
            int l = 0, r = n;
            int x = target - nums[i];
            while(l < r) {
                int mid = (l+r)>>1;
                if(x <= beans[mid].value) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            if(l == n) continue;
            if (beans[l].index == i) continue;
            if(beans[l].value == x) {
                ans.push_back(beans[l].index);
                ans.push_back(i);
                break;
            }
        
        }

        return ans;
    }
};
// @lc code=end

