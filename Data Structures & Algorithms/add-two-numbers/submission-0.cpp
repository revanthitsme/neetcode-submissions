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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* prev = new ListNode();
        ListNode* addprev = prev;
        while (temp1 || temp2)
        {
            if (temp1 && temp2)
            {
                int a = temp1->val;
                int b = temp2->val;                
                ListNode* curr = new ListNode((a+b+carry)%10);
                carry = (a+b+carry)/10;
                prev->next = curr;
                prev = curr;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else if (temp1)
            {
                int a = temp1->val;
                ListNode* curr = new ListNode((a+carry)%10);
                carry = (a+carry)/10;
                prev->next = curr;
                prev = curr;
                temp1 = temp1->next;                
            }
            else if (temp2)
            {
                int b = temp2->val;
                ListNode* curr = new ListNode((b+carry)%10);
                carry = (b+carry)/10;
                prev->next = curr;
                prev = curr;  
                temp2 = temp2->next;                 
            }
        }

        if (carry)
        {
            ListNode* curr = new ListNode(carry);
            prev->next = curr;
        }

        return addprev->next;
    }

};
