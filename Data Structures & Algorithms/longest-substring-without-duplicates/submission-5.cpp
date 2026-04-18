class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> dict;
        int l = 0;
        int longest = 0;

        for (int r = 0; r < s.length(); r++)
        {
            if (dict.find(s[r]) == dict.end())
            {
                dict.insert(s[r]);
                longest = max(r-l+1, longest);
            }
            else
            {
                while (l < r)
                {
                    if (s[l] == s[r])
                    {   
                        l++;
                        break;
                    }
                    dict.erase(s[l]);
                    l++;
                }
            }
            // cout << l << ' ' << r << ' ' << longest << '\n';
        }
        return longest;
    }
};
