class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {

        int n = online.size();

        vector<vector<pair<int,int>>> graph(n);
        vector<int> indegree(n, 0);

        int maxCost = 0;

        // Build graph
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];

            graph[u].push_back({v, cost});
            indegree[v]++;

            maxCost = max(maxCost, cost);
        }

        // Topological Sort (Kahn's Algorithm)
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            topo.push_back(u);

            for (auto &it : graph[u]) {
                indegree[it.first]--;
                if (indegree[it.first] == 0)
                    q.push(it.first);
            }
        }

        auto check = [&](int limit) {

            const long long INF = 1e18;
            vector<long long> dist(n, INF);

            dist[0] = 0;

            for (int u : topo) {

                if (dist[u] == INF)
                    continue;

                // Intermediate offline node cannot be used
                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto &edge : graph[u]) {

                    int v = edge.first;
                    int cost = edge.second;

                    // Only keep edges having cost >= limit
                    if (cost < limit)
                        continue;

                    // Intermediate offline node
                    if (v != n - 1 && !online[v])
                        continue;

                    dist[v] = min(dist[v], dist[u] + cost);
                }
            }

            return dist[n - 1] <= k;
        };

        int low = 0;
        int high = maxCost;
        int ans = -1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};