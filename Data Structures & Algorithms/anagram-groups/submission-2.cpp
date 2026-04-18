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
        vector<string> cp = strs;
        vector<vector<string>> res;
        unordered_map<string, vector<string>> maps;
        int len = strs.size();
        for(int i=0;i<len;i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            maps[s].push_back(cp[i]);
        }
        for(auto x:maps) {
            res.push_back(x.second);
        }
        return res;
    }
};
