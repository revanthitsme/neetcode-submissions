class Solution {
public:
    bool isalphanum(char a)
    {
        if ((a >= 'A' && a <= 'Z') ||
            (a >= '0' && a <= '9') ||
            (a >= 'a' && a <= 'z'))
        {
            cout << a << '\n';
            return true;
        }
        return false;
    }

    bool isPalindrome(string s) {
        int len = s.size();
        int i = 0; 
        int j = len -1;
        while (i <= j)
        {
            if (!isalphanum(s[i]))
                i++;
            else if (!isalphanum(s[j]))
                j--;
            else
            {
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                i++;
                j--;
            }

        }
        return true;
    }
};
