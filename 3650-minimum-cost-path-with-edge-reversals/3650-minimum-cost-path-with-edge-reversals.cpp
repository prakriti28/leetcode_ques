class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, e[2]});
            adj[v].push_back({u, 2 * e[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0}); // {cost, node}

        while (!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if (cost > dist[node])
                continue;

            if (node == n - 1)
                return cost;

            for (auto& [next, wt] : adj[node]) {
                if (dist[next] > cost + wt) {
                    dist[next] = cost + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return -1;
    }
};
