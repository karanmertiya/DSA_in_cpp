// Time Complexity: O(N log 10)
// Space Complexity: O(U + T)
// Explanation: Use a hash map to map user to their followees. Use another map to map user to their tweets. For news feed, use a Max-Heap to extract the 10 most recent tweets from the user and their followees.

class Twitter {
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time = 0;
public:
    Twitter() {}
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto t : tweets[userId]) pq.push(t);
        for(int f : followers[userId]) {
            for(auto t : tweets[f]) pq.push(t);
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

