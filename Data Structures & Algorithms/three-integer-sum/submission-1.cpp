class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<tuple<int,int,int>> s;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); i++)
        {
            int a = nums[i];
            int target = 0-a;

            int j = i+1;
            int k = nums.size()-1;
            while (j < nums.size()-1 && j < k)
            {
                if (nums[j]+nums[k] > target)
                    k--;
                else if (nums[j]+nums[k] < target)
                    j++;
                else
                {
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
            }
        }

        for (auto [e,f,g] : s)
        {
            res.push_back({e, f, g});
        }

        return res;
    }
};
