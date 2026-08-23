class CountSquares {

public:
    CountSquares() {
        
    }
    struct PairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>{}(p.first) ^ (hash<int>{}(p.second) << 1);
        }
    };
    unordered_map <pair<int,int>,int, PairHash> points;
    int xlow = INT_MAX;
    int ylow = INT_MAX;
    int xhigh = INT_MIN;
    int yhigh = INT_MIN;

    
    void add(vector<int> point) {
        // points.push_back({point[0], point[1]});
        int x = point[0];
        int y = point[1];

        points[{x, y}]++;

        xlow = min(xlow, x);
        xhigh = max(xhigh, x);
        ylow = min(ylow, y);
        yhigh = max(yhigh, y);
    }
    
    int count(vector<int> point) {
        // 4 quadrants
        if (point[0] < xlow || point[0] > xhigh ||
            point[1] < ylow || point[1] > yhigh)
        {
            return 0;
        }

        cout << "xlow: " << xlow << " xhigh: " << xhigh << " ylow: " << ylow << " yhigh: " << yhigh << '\n';
        int res = 0;
        // 1st quadrant
        int q1 = (point[0]-xlow) > (yhigh - point[1]) ? (yhigh - point[1]) : (point[0] - xlow);
        for (int i=1; i<=q1; i++)
        {
            if (points.find({point[0]-i,point[1]}) != points.end() &&
                points.find({point[0]-i,point[1]+i}) != points.end() &&
                points.find({point[0], point[1]+i}) != points.end())
            {
                int a = points[{point[0]-i,point[1]}];
                int b = points[{point[0]-i,point[1]+i}];
                int c = points[{point[0], point[1]+i}];
                res += a*b*c;
                // res+= points.find({point[0]-i,point[1]})*points.find({point[0]-i,point[1]+i})*points.find({point[0], point[1]+i});
            }
        }
        cout << "res: " << res << '\n';

        int q2 = (xhigh - point[0]) > (yhigh - point[1]) ? (yhigh - point[1]) : (xhigh - point[0]);
        for (int i=1; i<=q2; i++)
        {
            if (points.find({point[0]+i,point[1]}) != points.end() &&
                points.find({point[0]+i,point[1]+i}) != points.end() &&
                points.find({point[0], point[1]+i}) != points.end())
            {
                int a = points[{point[0]+i,point[1]}];
                int b = points[{point[0]+i,point[1]+i}];
                int c = points[{point[0], point[1]+i}];
                res += a*b*c;
            }
        }
        cout << "res: " << res << '\n';

        int q3 = (point[0]-xlow) > (point[1]-ylow) ? (point[1]-ylow) : (point[0]-xlow);
        cout << "q3: " << q3 << '\n';
        for (int i=1; i<=q3; i++)
        {
            if (points.find({point[0]-i,point[1]}) != points.end() &&
                points.find({point[0]-i,point[1]-i}) != points.end() &&
                points.find({point[0], point[1]-i}) != points.end())
            {
                int a = points[{point[0]-i,point[1]}];
                int b = points[{point[0]-i,point[1]-i}];
                int c = points[{point[0], point[1]-i}];
                res += a*b*c;            
            }
        }
        cout << "res: " << res << '\n';

        int q4 = (xhigh - point[0]) > (point[1]-ylow) ? (point[1]-ylow) : (xhigh - point[0]);
        for (int i=1; i<=q4; i++)
        {
            if (points.find({point[0]+i,point[1]}) != points.end() &&
                points.find({point[0]+i,point[1]-i}) != points.end() &&
                points.find({point[0], point[1]-i}) != points.end())
            {
                int a = points[{point[0]+i,point[1]}];
                int b = points[{point[0]+i,point[1]-i}];
                int c = points[{point[0], point[1]-i}];
                res += a*b*c;             
            }
        }
        cout << "res: " << res << '\n';
        return res;
    }
};
