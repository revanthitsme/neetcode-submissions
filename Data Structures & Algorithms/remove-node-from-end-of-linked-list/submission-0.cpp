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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int N = 0;
        while (temp)
        {
            temp = temp->next;
            N++;
        }

        if (N == n)
            return head->next;
        else
        {
            temp = head;
            int kate = N-n-1;
            int i = 0;
            while (temp)
            {
                if (i == kate)
                {
                    temp->next = temp->next->next;
                    break;
                }
                else
                {
                    temp = temp->next;
                }
                i++;
            }
            return head;
        }

    }
};
