class Solution {
public:
    int reverse(int x) {
        int modulusx = 0;
        bool isneg = false;
        int res = 0;

        if (x < 0)
        {
            isneg = true;
            if (x == INT_MIN)
            {
                return 0;
            }
            else
            {
                modulusx = x* (-1);
            }
        }
        else
            modulusx = x;

        while (modulusx != 0)
        {
            int rem = modulusx % 10;
            modulusx /= 10;
            if (res <= (INT_MAX/10))
            {
                res = res*10 + rem;
            }
            else
                return 0;
        }

        if (isneg)
        {
            return res*(-1);
        }
        else
            return res;


    }
};
