class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>> temp;
        stack<double> time;

        for (int i=0;i<position.size();i++)
        {   double t = (double)(target-position[i])/(double)speed[i];
            temp.push_back({position[i], t});
        }
        sort(temp.begin(), temp.end());
        for (auto i : temp)
        {
            while (!time.empty() && time.top() <= i.second)
                time.pop();
            time.push(i.second);
            cout << i.first << ' ' << i.second << '\n';
        }

        return time.size();
    }
};
