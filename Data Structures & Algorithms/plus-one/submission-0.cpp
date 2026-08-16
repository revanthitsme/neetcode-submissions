class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool extradigit = true;

        for (int i = 0; i < digits.size(); i++)
        {
            if (digits[i] != 9)
            {
                extradigit = false;
                break;
            }
        }

        if (extradigit)
        {
            vector<int> res(digits.size() + 1, 0);
            res[0] = 1;
            return res;
        }
        else
        {
            vector<int> res(digits.size(), 0);
            bool carry = true;
            for (int i = digits.size() - 1; i >=0 ; i--)
            {
                if (carry)
                {
                    if (1 + digits[i] == 10)
                    {
                        res[i] = 0;
                        carry = true;
                    }
                    else
                    {
                        res[i] = 1 + digits[i];
                        carry = false;
                    }
                }
                else
                {
                    res[i] = digits[i];
                }
            }
            return res;
        }
        


    }
};
