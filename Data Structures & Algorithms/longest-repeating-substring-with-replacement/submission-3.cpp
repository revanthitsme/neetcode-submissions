class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> dict(26,0);
        int maxFreq = INT_MIN;
        int l = 0;
        int ans = 0;
        for (int r = 0; r < s.length(); r++)
        {
            dict[s[r]-'A']++;
            maxFreq = max(maxFreq, dict[s[r]-'A']);

            while ((r-l+1) -maxFreq > k)
            {   
                dict[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};
