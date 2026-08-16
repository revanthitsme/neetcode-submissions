class Solution {
public:
    int squaredigits(int n)
    {
        int res = 0;
        while (n != 0)
        {
            int rem = n % 10;
            n = n / 10;
            res += rem*rem;
        }
        return res;
    }
    bool isHappy(int n) {
        unordered_set<int> possiblenumbers;
        if (n == 1)
            return true;
        possiblenumbers.insert(n);
        int squaren = squaredigits(n);

        while (squaren != 1 && possiblenumbers.find(squaren) == possiblenumbers.end())
        {
            possiblenumbers.insert(squaren);
            squaren = squaredigits(squaren);
        }
        if (squaren == 1)
            return true;
        
        if (possiblenumbers.find(squaren) != possiblenumbers.end())
            return false;
    }
};
