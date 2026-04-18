class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> dict;
        for (int i=0; i<nums.size(); i++)
        {
            if (dict.find(nums[i]) != dict.end())
            {
                return true;
            }
            else
            {
                dict.insert({nums[i], 1});
            }
        }
        return false;
    }
};