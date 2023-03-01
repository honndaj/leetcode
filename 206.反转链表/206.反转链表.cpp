/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *blank = new ListNode(-1, head), *p = blank->next, *pp = nullptr;
        while(p != nullptr) {
            pp = p->next;
            if(p == blank->next){
                p->next = nullptr;
            }else {
                p->next = blank->next;
            }
            blank->next = p;
            p = pp;
        }
        return blank->next;
    }
};
// @lc code=end

