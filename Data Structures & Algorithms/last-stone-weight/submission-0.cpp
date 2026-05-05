class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>> pq;

        for (int i = 0; i < stones.size(); i++)
        {
            pq.push(stones[i]);
        }

        while (pq.size() >= 2)
        {
            int elem1 = pq.top();
            pq.pop();
            int elem2 = pq.top();
            pq.pop();
            if (elem1 - elem2 > 0)
                pq.push(elem1-elem2);
        }
        
        if (pq.empty())
            return 0;
        else
            return pq.top();
    }
};
