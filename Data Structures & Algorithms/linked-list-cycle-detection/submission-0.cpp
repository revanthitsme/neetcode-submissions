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
    bool hasCycle(ListNode* head) {
        ListNode* oneshift = head;
        ListNode* twoshift = head;

        if (head == nullptr || head->next == nullptr)
            return false;
        else
        {
            oneshift = head;
            twoshift = head->next;
        }

        while (oneshift != nullptr && twoshift != nullptr)
        {
            if (oneshift == twoshift)
                return true;
            else
            {
                oneshift = oneshift->next;
                if (twoshift->next == nullptr || twoshift->next->next == nullptr)
                    return false;
                else
                    twoshift = twoshift->next->next;
            }
        }

        return false;
    }
};
