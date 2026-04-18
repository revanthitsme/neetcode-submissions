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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *ans;
        ListNode *curr1 = list1;
        ListNode *curr2 = list2;

        if (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                ans = list1;
                curr1 = list1->next;
            }
            else
            {
                ans = list2;
                curr2 = list2->next;
            }
        }
        else if (list1)
        {
            ans = list1;
            curr1 = curr1->next;
        }
        else if (list2)
        {
            ans = list2;
            curr2 = curr2->next;
        }
        else
            ans = NULL;

        ListNode *head = ans;

        while (curr1 && curr2)
        {
            cout << ans->val << ' ' << curr1->val << ' ' << curr2->val << '\n';
            if (curr1->val <= curr2->val)
            {
                ans->next = curr1;
                curr1 = curr1->next;
            }
            else
            {
                ans->next = curr2;
                curr2 = curr2->next;
            }
            ans = ans->next;
        }

        if (curr1)
            ans->next = curr1;
        
        if (curr2)
            ans->next = curr2;

        return head;
    }
};
