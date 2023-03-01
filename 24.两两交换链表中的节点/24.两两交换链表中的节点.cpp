/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode* blank = new ListNode(-1, head);
        ListNode* p = head, *q = head->next, *pre = blank;
        while(p != nullptr && q != nullptr) {
            pre->next = q;
            pre = p;
            p->next = q->next;
            q->next = p;

            p = p->next;
            if(p == nullptr) break;
            q = p->next;
        }
        return blank->next;
    }
};
// @lc code=end

