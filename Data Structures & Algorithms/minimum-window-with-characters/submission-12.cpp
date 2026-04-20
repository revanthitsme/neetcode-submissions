class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tcount(128,0);
        for (char c : t)
        {
            tcount[c]++;
        }

        int reqlen = t.length();
        int minlen = INT_MAX;
        int startIdx = 0;
        int left = 0;
        int right = 0;

        while (right < s.length())
        {
            if (tcount[s[right]] > 0)
            {
                reqlen--;
            }

            tcount[s[right]]--;
            right++;
            if (reqlen == 0)
            {

            }

            while (reqlen == 0)
            {

                if (right - left < minlen)
                {
                    minlen = right-left;
                    startIdx = left;
                }

                tcount[s[left]]++;

                if (tcount[s[left]] > 0)
                {          
                    reqlen++;
                }

                left++;
            }
        }

        return (minlen == INT_MAX) ? "" : s.substr(startIdx, minlen);
        
    }
};
