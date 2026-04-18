class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        set<tuple<int,int,int>> s;
        sort(nums.begin(), nums.end());

        for (int i=0; i<nums.size(); i++)
        {
            if (i>0 && nums[i] == nums[i-1])
              continue;
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
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    // Skip duplicate third elements
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }

        // for (auto [e,f,g] : s)
        // {
        //     res.push_back({e, f, g});
        // }

        return res;
    }
};
