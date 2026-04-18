class TimeMap {
    unordered_map<string, string> store;
    vector<int> ts;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        ts.push_back(timestamp);
        store[key + to_string(timestamp)] = value;
    }
    
    string get(string key, int timestamp) {
        if (store.find(key + to_string(timestamp)) != store.end())
            return store[key + to_string(timestamp)];
        else
        {
            int l = 0;
            int r = ts.size() - 1;
            int kate = 0;
            while(l <= r)
            {
                int mid = l + ((r - l)/2);
                if (ts[mid] > timestamp)
                {
                    r = mid - 1;
                }
                else if (ts[mid] < timestamp)
                {
                    if (mid == ts.size() - 1)
                    {
                        kate = mid;
                        break;
                    }

                    if (mid+1 < ts.size() && ts[mid+1] > timestamp)
                    {
                        kate = mid;
                        break;
                    }
                    else
                        l = mid + 1;
                }
                else
                {
                    kate = mid;
                    break;
                }
            }

            if (l > r)
            {
                return "";
            }
            while (kate >= 0 && store.find(key + to_string(ts[kate])) == store.end())
            {
                kate--;
            }

            if (kate < 0)
                return "";
            else
                return store[key + to_string(ts[kate])];
        }
    }
};
