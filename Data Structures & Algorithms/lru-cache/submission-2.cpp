class LRUCache {
    struct Node
    {
        pair<int,int> val;
        Node* prev;
        Node* next;
    };
    unordered_map<int, Node*> store;
    int maxstrg;
    int count;
    Node* head;
    Node* tail;
public:
    LRUCache(int capacity) {
        maxstrg = capacity;
        count = 0;
        head = NULL;
        tail = NULL;
    }

    void shifttoTop(Node* node)
    {            
        if (head != node)
        {
            Node* temp = node;
            Node* prev = node->prev;
            Node* next = node->next;
            if (prev)
                prev->next = next;
            if (next)
                next->prev = prev;
            
            if (node == tail)
                tail = prev;

            Node* temp1 = head;
            temp->prev = NULL;
            temp->next = head;
            temp1->prev = temp;
            head = temp;
        }
    }
    
    int get(int key) {
        if (store.find(key) != store.end())
        {
            shifttoTop(store[key]);
            return (head->val).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (store.find(key) != store.end())
        {
            (store[key]->val).second = value;
            shifttoTop(store[key]);
        }
        else
        {
            if (count >= maxstrg)
            {
                Node* temp = tail;
                tail = temp->prev;
                if (tail)
                    tail->next = NULL;
                int delkey = (temp->val).first;
                store.erase(delkey);
                count --;
                if (count == 0)
                    head = NULL;
            }
            Node *newnode = new Node();
            newnode->next = head;
            newnode->val = {key, value};
            newnode->prev = NULL;
            if (head)
                head->prev = newnode;
            head = newnode;
            count++;
            if (count == 1)
                tail = head;
            
            store[key] = head;
            cout << head->val.first << ' ' << head->val.second << '\n';
        }
    }
};
