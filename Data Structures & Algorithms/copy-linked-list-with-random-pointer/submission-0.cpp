/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, int> store1;
        unordered_map<int, Node*> store2;

        Node* temp = head;
        int n = 0;
        while (temp)
        {
            store1[temp] = n;
            temp = temp->next;
            n++;
        }

        int j = 0;
        temp = head;
        Node* prev = new Node(0);
        Node* newhead = prev;
        while (j < n)
        {
            Node *temp1 = new Node(temp->val);
            store2[j] = temp1;
            prev->next = temp1;
            prev = temp1;
            temp = temp->next;
            j++;
        }
        newhead = newhead->next;

        j = 0;
        temp = head;
        Node *temp1 = newhead;
        while (j < n)
        {
            if (temp->random)
            {               
                temp1->random = (Node *)store2[store1[temp->random]];
            }
            else
            {
                temp1->random = NULL;
            }
            temp = temp->next;
            temp1 = temp1->next;
            j++;
        }

    return newhead;
    }
};
