class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> suffix(nums.size(), INT_MAX);
        vector<int> res;
        int prev = INT_MAX;
        int suff = INT_MAX;
        for (int i=0; i<nums.size(); i++)
        {
            prefix.push_back(prev);
            if (prev==INT_MAX)
                prev = nums[i];
            else
                prev = prev*nums[i];
        }

        for (int j=nums.size()-1; j >=0; j--)
        {
            suffix[j] = suff;
            if (suff == INT_MAX)
                suff = nums[j];
            else
                suff = suff*nums[j];
        }   

        for (int i=0;i<nums.size();i++)
        {
            if (prefix[i] == INT_MAX)
                res.push_back(suffix[i]);
            else if (suffix[i] == INT_MAX)
                res.push_back(prefix[i]);
            else
                res.push_back(prefix[i]*suffix[i]);
        }
        return res;

    }
};
