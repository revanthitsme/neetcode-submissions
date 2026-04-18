class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> dict;
        for (int i=0; i<nums.size(); i++)
        {
            dict.insert(nums[i]);
        }

        unordered_map<int, int> stseq;
        unordered_set<int> temp;
        for (int i=0; i<nums.size(); i++)
        {
            int j = 1;
            if (temp.find(nums[i]) == temp.end() &&
                stseq.find(nums[i]) == stseq.end())
            {
                stseq[nums[i]]++;
                while (dict.find(nums[i]+j) != dict.end())
                {
                    stseq[nums[i]]++;
                    temp.insert(nums[i]+j);
                    j++;
                }
            }
        }

        int res = 0;
        for (auto p : stseq)
        {
            if ((p.second) > res)
                res = p.second;
        }
        return res;
    }
};
