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
        ListNode *tCurrent = head;
        ListNode *tPrevious = nullptr;

        while (tCurrent != nullptr)
        {
            ListNode *tNext = tCurrent->next;
            tCurrent->next = tPrevious;
            tPrevious = tCurrent;
            tCurrent = tNext;
        }

        return tPrevious;
    }
};


// So we [1] -> [2] -> [3] and we need to do  [1] <- [2] -> [3] then 