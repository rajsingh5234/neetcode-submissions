
class User {
    public:
        int userId;
        queue<pair<int, int>> q;
        unordered_set<int> followings;

        User(int userId){
            this->userId = userId;
            followings.insert(userId);
        }

        void addTweet(int time, int id){
            q.push({time, id});
            if(q.size() > 10) q.pop();
        }

        void follow(int id){
            if(!followings.count(id)){
                followings.insert(id);
            }
        }
        void unfollow(int id){
            if(id == this->userId) return;
            if(followings.count(id)){
                followings.erase(id);
            }
        }

        vector<pair<int, int>> getTweets(){
            vector<pair<int, int>> v;

            int n = q.size();

            while(n--){
                v.push_back(q.front());
                q.push(q.front());
                q.pop();
            }

            return v;
        }
};

class Twitter {
public:

    unordered_map<int, User*> mp;
    int time;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        if(!mp.count(userId)){
            mp[userId] = new User(userId);
        }
        time++;
        User* user = mp[userId];
        user->addTweet(time, tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        if(!mp.count(userId)) return {};

        User* user = mp[userId];

        priority_queue<pair<int, int>, 
        vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;

        for(auto id : user->followings){

            User* u = mp[id];

            vector<pair<int, int>> tweets = u->getTweets();

            for(auto &p : tweets) {
                pq.push(p);

                if(pq.size() > 10) pq.pop();
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(!mp.count(followerId)){
            mp[followerId] = new User(followerId);
        }
        if(!mp.count(followeeId)){
            mp[followeeId] = new User(followeeId);
        }

        User* user = mp[followerId];
        user->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(!mp.count(followerId)){
            mp[followerId] = new User(followerId);
        }
        if(!mp.count(followeeId)){
            mp[followeeId] = new User(followeeId);
        }

        User* user = mp[followerId];
        user->unfollow(followeeId);
    }
};
