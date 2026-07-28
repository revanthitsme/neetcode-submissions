class Solution {
public:
    int getSum(int a, int b) {
        int16_t a1 = (int16_t)a;
        int16_t b1 = (int16_t)b;
        bool carry = false;
        int16_t res = 0;
        for (int i=0; i<16; i++)
        {
            bool ia = (a1 >> i) & 1;
            bool ib = (b1 >> i) & 1;
            
            if (carry)
            {
                if (ia && ib)
                {
                    carry = true;
                    res |= (1 << i);
                }
                else if (ia || ib)
                {
                    carry = true;
                }
                else
                {
                    carry = false;
                    res |= (1 << i);
                }
            }
            else
            {
                if (ia && ib)
                {
                    carry = true;
                }
                else if (ia || ib)
                {
                    carry = false;
                    res |= (1 << i);
                }
                else
                {
                    carry = false;
                }
            }
        }

        return (int)res;
    }
};
