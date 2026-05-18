class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";

        priority_queue<pair<int, char>> pq;

        if(a>0) pq.push({a, 'a'});
        if(b>0) pq.push({b, 'b'});
        if(c>0) pq.push({c, 'c'});

        while(pq.size() > 1){
            int af = pq.top().first;
            char a = pq.top().second;
            pq.pop();

            int n = ans.size();

            if(n>=2 && ans[n-1] == a && ans[n-2] == a){
                int bf = pq.top().first;
                char b = pq.top().second;
                pq.pop();

                ans += b;
                bf--;
                if(bf > 0) pq.push({bf, b});
            }
            else{
                ans += a;
                af--;
                if(af > 0){
                    ans += a;
                    af--;
                }
            }

            if(af > 0) pq.push({af, a});
        }

        if(pq.size() == 1){
            int af = pq.top().first;
            char a = pq.top().second;
            pq.pop();
            ans += a;
            af--;
            if(af > 0){
                ans += a;
                af--;
            }
        }

        return ans;
    }
};