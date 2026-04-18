class Solution {
public:

    string encode(vector<string>& strs) {
        string encstr = "";

        for (int i=0; i<strs.size(); i++)
        {
            int strlen = strs[i].size();
            string numstr = to_string(strlen);

            while (numstr.size() < 3)
               numstr = '0' + numstr;
            encstr = encstr + numstr + strs[i];
        }
        // cout << encstr <<'\n';
        return encstr;

    }

    vector<string> decode(string s) {
        int pos = 0;
        vector<string> decstrs;
        while (pos < s.size())
        {
            int strnum = (s[pos]-'0')*100 + (s[pos+1]-'0')*10 + (s[pos+2] - '0');
            // cout << strnum << '\n';
            // int strnum = 0;
            // for (int i=0; i<3;i++)
            // {
            //     strnum = strnum*10 + (strn[i]-'0');
            // }
            string str = "";
            pos = pos+3;
            int i = 0;
            while (i < strnum)
            {
                str = str + s[pos];
                pos++;
                i++;
            }
            // cout << str << '\n';

            decstrs.push_back(str);
        }

        return decstrs;
    }
};
