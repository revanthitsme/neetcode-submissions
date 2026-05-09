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
        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        int totalcnt = 0;

        for (auto i : follows[userId])
        {
            for (int k = tweets[i].size() -1 ; k>=0; k--)
            {
                if (pq.size() >= 10 && pq.top().first > tweets[i][k].first)
                    break;
                
                if (pq.size() >= 10 && pq.top().first < tweets[i][k].first)
                {
                    pq.pop();
                    totalcnt--;
                } 

                if (pq.size() < 10)
                {
                    pq.push(tweets[i][k]);
                    totalcnt++;
                }
            }
            // for (auto p : tweets[i])
            // {
            //     cout << i << ' ' << p.first << ' ' << p.second <<'\n';
            //     if (pq.size() >= 10 && pq.top().first < p.first)
            //     {
            //         pq.pop();
            //         totalcnt--;
            //     }

            //     if (pq.size() < 10)
            //     {
            //         pq.push(p);
            //         totalcnt++;
            //     }
            // }              
        }

        vector<int> res(totalcnt, 0);
        for (int i = totalcnt -1; i >=0; i--)
        {
            res[i] = pq.top().second;
            pq.pop();
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
