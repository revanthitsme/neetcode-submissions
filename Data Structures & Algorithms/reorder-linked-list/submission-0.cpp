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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }

        int i = 0;

        temp = new ListNode();

        int breakpoint = (n+1)/2;

        cout << n << ' ' << breakpoint << '\n';

        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr)
        {


            if (i >= breakpoint)
            {
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            else
            {
                if (i == breakpoint - 1)
                {
                    temp = curr->next;
                    curr->next = NULL;
                    curr = temp;
                }
                else
                    curr = curr->next;
            }
            i++;
        }

        ListNode *secondhead = prev;

        ListNode* curr1 = head;
        ListNode* curr2 = secondhead;
        ListNode* temp1;
        ListNode* temp2;
        while (curr1 && curr2)
        {
            temp1 = curr1->next;
            temp2 = curr2->next;

            curr1->next = curr2;
            curr2->next = temp1;

            curr1 = temp1;
            curr2 = temp2;
        }

    }
};
