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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        if (lists.empty())
        {
            return nullptr;
        }        

        return mergeRange(lists, 0, static_cast<int>(lists.size()) - 1);       
    }
    
    ListNode* mergeRange(std::vector<ListNode*> &aVector, int start, int end)
    {
        if (start == end)
        {
            return aVector[start];
        }

        int tMiddle = start + (end - start) / 2;
        ListNode *tLeft = mergeRange(aVector, start, tMiddle);
        ListNode *tRight = mergeRange(aVector, tMiddle + 1, end);

        return mergeLists(tLeft, tRight);
    }

    ListNode* mergeLists(ListNode *t1, ListNode *t2)
    {
        if (t1 == nullptr)
        {
            return t2;
        }
        if (t2 == nullptr)
        {
            return t1;
        }

        ListNode tDummy{};
        ListNode *tTracker = &tDummy;

        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1->val <= t2->val)
            {
                tTracker->next = t1;
                t1 = t1->next;
                tTracker = tTracker->next;
            }
            else 
            {
                tTracker->next = t2;
                t2 = t2->next;
                tTracker = tTracker->next;
            }
        }

        if (t1)
        {
            tTracker->next = t1;
        }
        if (t2)
        {
            tTracker->next = t2;
        }

        return tDummy.next;
    }
};
