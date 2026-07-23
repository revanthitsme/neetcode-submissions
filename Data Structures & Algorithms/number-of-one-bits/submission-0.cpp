class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = n;
        int res = 0;
        while (ans > 0)
        {
            if (ans % 2 == 1)
                res++;
            ans = ans/2;
        }
        return res;
    }
};
