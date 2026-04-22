class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> idx;
        vector<int> res;

        for (int i=0; i < nums.size(); i++)
        {
            if (!idx.empty() && idx.front() == i -k)
            {
                idx.pop_front();
            }

            while (!idx.empty() && nums[idx.back()] < nums[i])
            {
                idx.pop_back();
            }

            idx.push_back(i);

            if (i >= k - 1)
                res.push_back(nums[idx.front()]);
        }
        return res;
    }
};
