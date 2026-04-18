class Solution {

public:
    string getcharcount(string s)
    {        
        vector<int> a(27, 0);
        string res;
        for (int i=0; i<s.size(); i++)
        {
            a[s[i]-'a']++;
        }
        for (int i=0; i<27; i++)
        {
            res.push_back('0' + a[i]);
        }
        return res;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        vector<vector<string>> result;
        for (int i = 0; i < strs.size(); i++)
        {           
            string charcount = getcharcount(strs[i]);
            if (dict.find(charcount) != dict.end())
                dict[charcount].push_back(strs[i]);
            else
                dict.insert({charcount, {strs[i]}});
        }

        for (const auto& p : dict)
        {
            result.push_back(p.second);
        }
        return result;
    }
};
