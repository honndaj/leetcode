/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        vector<pair<int,int>> a;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for(pair<int,int> kv : mp) {
            a.push_back(kv);//value count
        }
        qsort(a, k, 0, a.size());
        vector<int> ans;
        for(int i = a.size()-1; ans.size() < k;i--) {
            ans.push_back(a[i].first);
        }
        return ans;
    }

    void qsort(vector<pair<int,int>>& a, int k, int l, int r) {
        if(r-l<=1) return;
        int picked = rand() % (r-l) + l, i = l, j = r-1;
        swap(a[l], a[picked]);
        pair<int, int> pivot = a[l];
        while(i < j) {
            while(i < j && a[j].second > pivot.second) j--;
            if(i < j) {
                a[i++] = a[j];
            }
            while(i < j && a[i].second <= pivot.second) i++;
            if(i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = pivot;
        if(r-i-1 >= k) {
            qsort(a, k, i+1, r);
        }else {
            qsort(a, k-(r-i), l, i);
        }
    }
};
// @lc code=end

