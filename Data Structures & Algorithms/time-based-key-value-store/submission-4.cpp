class TimeMap {
    unordered_map<string, vector<pair<int,string>>> store;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (store.find(key) == store.end())
            return "";
        else
        {
            int vs = store[key].size();           
            int l = 0;
            int r = vs - 1;
            string ans = "";
            while (l <= r)
            {
                int mid = (l+r)/2;
                if (store[key][mid].first > timestamp)
                    r = mid - 1;
                else if (store[key][mid].first <= timestamp)
                {
                    ans = store[key][mid].second;
                    l = mid + 1;
                }
            }

            return ans;
        }
    }
};
