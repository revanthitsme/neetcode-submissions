class Twitter {
    vector<int> users;
    unordered_map<int,unordered_set<int>> follows;
    unordered_map<int, vector<pair<int,int>>> tweets;
    int tweetcnt;
public:
    Twitter() {
        tweetcnt = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetcnt++;
        tweets[userId].push_back({tweetcnt, tweetId});
        follows[userId].insert(userId);
    }
    
    vector<int> getNewsFeed(int userId) {
        struct Node {
            int time;
            int tweetId;
            int userId;
            int idx;
        };

        auto cmp = [](const Node& a, const Node& b) {
            return a.time < b.time; // max-heap by time
        };

        priority_queue<Node, vector<Node>, decltype(cmp)> pq(cmp);

        // make sure user follows themselves
        follows[userId].insert(userId);

        for (int f : follows[userId]) {
            auto& arr = tweets[f];
            if (!arr.empty()) {
                int idx = (int)arr.size() - 1;
                pq.push({arr[idx].first, arr[idx].second, f, idx});
            }
        }

        vector<int> res;
        while (!pq.empty() && (int)res.size() < 10) {
            auto cur = pq.top();
            pq.pop();
            res.push_back(cur.tweetId);

            int nextIdx = cur.idx - 1;
            if (nextIdx >= 0) {
                auto& arr = tweets[cur.userId];
                pq.push({arr[nextIdx].first, arr[nextIdx].second, cur.userId, nextIdx});
            }
        }

        return res;    
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            follows[followerId].erase(followeeId);
    }
};
