// Time Complexity: O(K log K) for feed where K is 10.
// Space Complexity: O(Total Tweets + Follow Relations)
// Explanation: Maintain a timestamp for tweets. Each user has a list of tweets and a set of followed users. To get the news feed, gather the most recent tweets from the user and all followees using a max-heap (like merging K sorted lists).

class Twitter {
    int time;
    unordered_map<int, unordered_set<int>> follows;
    unordered_map<int, vector<pair<int, int>>> tweets; // time, tweetId
public:
    Twitter() { time = 0; }
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto t : tweets[userId]) pq.push(t);
        for(int followee : follows[userId]) {
            for(auto t : tweets[followee]) pq.push(t);
        }
        vector<int> res;
        for(int i = 0; i < 10 && !pq.empty(); i++) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId) follows[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

