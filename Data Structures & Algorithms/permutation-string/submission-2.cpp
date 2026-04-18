class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int> count;
        for (int i=0; i< s1.length(); i++)
        {
            count[s1[i]-'a']++;
        }

        
        for (int r=0; r<s2.length()-s1.length()+1; r++)
        {
            unordered_map<int,int> temp = count;

            for (int i=0; i<s1.length(); i++)
            {
                if (temp.find(s2[i+r]-'a') == temp.end())
                    break;
                else
                {
                    if (temp[s2[i+r]-'a'] == 1)
                        temp.erase(s2[i+r]-'a');
                    else
                        temp[s2[i+r]-'a']--;
                }
            }
            if (temp.empty())
                return true;
        }
        return false;
    }
};
