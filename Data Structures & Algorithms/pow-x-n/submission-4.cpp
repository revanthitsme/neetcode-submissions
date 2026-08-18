class Solution {
public:
    double myPow(double x, int n) {
        unordered_map<int, double> xp;
        int k = 2;
        double res = 1.00000;
        xp[1] = x;
        xp[-1] = 1.00000/x;
        // bool neg = false;
        // bool intmin = false;

        // if (n < 0 && n > INT_MIN)
        // {
        //     neg = true;
        //     n = -1*n;
        // }
        // else
        // {
        //     n = (n+1)*(-1);
        // }



        if (n > 0)
        {
            k = 2;
            while (k <= n && (k-1)<= (INT_MAX-1)/2)
            {
                xp[k] = xp[k/2]*xp[k/2];
                if (k+1 > INT_MAX/2)
                    break;
                k = 2*k;
                
            }
        }
        else
        {
            k = -2;
            while (k >= n && (k+1) >= (INT_MAX+1)/2)
            {
                xp[k] = xp[k/2]*xp[k/2];
                if (k-1 < INT_MIN/2)
                    break;
                k=2*k;
            }
        }

        // for (auto x : xp)
        // {
        //     cout << x.first << ' ' << x.second << '\n';
        // }

        int dif = n;
        

        while (dif > 0)
        {
            if (k <= dif)
            {
                res *= xp[k];
                dif = dif - k;
            }
            else
            {
                k = k/2;
            }
            cout << k << ' ' << dif << ' ' << res <<'\n';
        }

        while (dif < 0)
        {
            if (k >= dif)
            {
                res*=xp[k];
                dif -= k;
            }
            else
            {
                k = k/2;
            }
        }

        cout << res <<'\n';

        // if (neg)
        // {
        //     if (intmin)
        //     {
        //         return 1.00000/(x*res);
        //     }
        //     else
        //         return 1.00000/res;
        // }
        // else
        return res;
    }
};
