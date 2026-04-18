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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* slow = head;
        ListNode* fast = head;
        int i = 0;
        int nextelements = 0;
        while (fast && i < k)
        {
            fast = fast->next;
            nextelements++;
            i++;
        }

        ListNode* prevgrpfn = NULL;
        ListNode* ans = NULL;
        i = 0;
        
        while (fast ||  (nextelements == k))
        {
            i = 0;
            nextelements = 0;
            ListNode* prev = NULL;
            ListNode* curr = slow;
            ListNode* currgrpfn = slow;
            while (i < k)
            {
                ListNode* temp1 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp1;
                i++; 

                if (fast)
                {
                    fast = fast->next;
                    nextelements++;
                }
            }

            if (!ans)
                ans = prev;

            if (prevgrpfn)
                prevgrpfn->next = prev;
            
            prevgrpfn = currgrpfn;            
            slow = curr;            
        }



        if (prevgrpfn)
            prevgrpfn->next = slow;

        if (!ans)
            return head;
        else
            return ans;
    }
};
