class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> count(26,0);
        for (int i=0; i<s1.length(); i++)
        {
            count[s1[i]-'a']++;
        }

        vector<int> temp(26,0);
        int l = 0;
        for (int r=0; r<s2.length(); r++)
        {   
            temp[s2[r]-'a']++;
            while (r-l+1 > s1.length()) 
            {
                temp[s2[l]-'a']--;
                l++;
            }
            
            if (temp == count)
                return true;
        }
        return false;
    }
};
