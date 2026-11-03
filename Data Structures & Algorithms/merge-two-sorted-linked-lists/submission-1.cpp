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
        if (list1 == nullptr)
        {
            return list2;
        }

        if (list2 == nullptr)
        {
            return list1;
        }

        ListNode *t1 = list1;
        ListNode *t2 = list2;

        ListNode tDummyStart = ListNode{};
        ListNode *tNewHead = &tDummyStart;
        
        while (t1 != nullptr && t2 != nullptr)
        {
            if (t1->val >= t2->val)
            {
                tNewHead->next = t2;
                t2 = t2->next;
            }
            else 
            {   
                tNewHead->next = t1;
                t1 = t1->next;
            }
            tNewHead = tNewHead->next;
        }

        if (t1 != nullptr)
        {
            tNewHead->next = t1;
        }
        else 
        {
            tNewHead->next = t2;
        }

        return tDummyStart.next;
    }
};
