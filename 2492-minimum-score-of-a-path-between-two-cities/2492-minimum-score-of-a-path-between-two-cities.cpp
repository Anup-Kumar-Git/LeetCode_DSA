class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int,int>>> graph(n + 1);

        for(auto &road : roads)
        {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<int> visited(n + 1, 0);
        queue<int> q;

        q.push(1);
        visited[1] = 1;

        int ans = INT_MAX;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto &it : graph[node])
            {
                int next = it.first;
                int dist = it.second;

                ans = min(ans, dist);

                if(!visited[next])
                {
                    visited[next] = 1;
                    q.push(next);
                }
            }
        }

        return ans;
    }
};