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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        bool cond = false;
        int k = lists.size();

        for (int i = 0; i < k; i++)
        {
            cond = cond || lists[i];
        }

        ListNode *dummy = new ListNode();
        ListNode *prev = dummy;
        while (cond)
        {
            ListNode* temp;
            int val = INT_MAX;
            int index = -1;
            cond = false;
            for (int i = 0; i < k; i++)
            {
                cond = cond || lists[i];
                if (lists[i] && lists[i]->val < val)
                {
                    index = i;
                    val = lists[i]->val;
                }
            }
            if (index >= 0 && index < k)
            {
                temp = lists[index];
                lists[index] = lists[index]->next;
                prev->next = temp;
                prev = prev->next;
            } 
        }

        return dummy->next;
    }
};
