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
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *tCurr = head;
        ListNode *tPrev = nullptr;

        while (tCurr != nullptr)
        {
            ListNode *tNext = tCurr->next;
            tCurr->next = tPrev;
            tPrev = tCurr;
            tCurr = tNext;
        }

        return tPrev;
    }
};
