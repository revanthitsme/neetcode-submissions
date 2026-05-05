class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<float,int>, vector<pair<float,int>>> pq;
        vector<vector<int>> res;
        for (int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];            
            float dist = sqrt(x*x + y*y);
            if (pq.size() >= k && dist < pq.top().first)
                pq.pop();
            if (pq.size() < k)
                pq.push({dist, i});
        }

        while (!pq.empty())
        {
            res.push_back(points[pq.top().second]);
            pq.pop();
        }
        return res;
    }
};
