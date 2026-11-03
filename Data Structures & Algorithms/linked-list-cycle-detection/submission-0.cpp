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
    bool hasCycle(ListNode* head) 
    {
        if (head == nullptr)
        {
            return false;
        }

        std::set<int*> tSetOfPointers;

        ListNode *tIter = head;
        while (tIter != nullptr && 
                tSetOfPointers.find(&tIter->val) == tSetOfPointers.end())
        {
            tSetOfPointers.insert(&tIter->val);
            tIter = tIter->next;
        }

        if (tIter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
