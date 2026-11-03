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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode tFakeStart;
        ListNode *tTracker = &tFakeStart;

        ListNode *t1 = list1;
        ListNode *t2 = list2;

        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1->val <= t2->val)
            {
                tTracker->next = t1;
                t1 = t1->next;
            }
            else 
            {
                tTracker->next = t2;
                t2 = t2->next;
            }
            
            tTracker = tTracker->next;
        }

        if (t1 != nullptr)
        {
            tTracker->next = t1;
        }
        else
        {
            tTracker->next = t2;
        }

        return tFakeStart.next;    
    }
};
