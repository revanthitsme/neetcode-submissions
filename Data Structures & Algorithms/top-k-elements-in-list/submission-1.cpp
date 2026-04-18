class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> dict;
        priority_queue<pair<int, int>, 
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;
        vector<int> res;
        for (int i=0; i<nums.size(); i++)
        {
            if (dict.find(nums[i]) != dict.end())
                dict[nums[i]]++;
            else
                dict[nums[i]] = 1;
        }

        for (auto p : dict)
        {
            pq.push({p.second, p.first});
            if (pq.size() > k)
                pq.pop();
        }

        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
