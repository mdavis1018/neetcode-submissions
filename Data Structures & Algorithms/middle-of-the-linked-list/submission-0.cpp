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
    ListNode* middleNode(ListNode* head) 
    {
        ListNode *tSlow = head;
        ListNode *tFast = head;

        while (tFast != nullptr && tFast->next != nullptr)
        {
            tSlow = tSlow->next;
            tFast = tFast->next;
            tFast = tFast->next;
        }    

        return tSlow;
    }
};