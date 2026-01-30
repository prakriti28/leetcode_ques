class Solution {
public:
    int solve(int src, int dst, vector<vector<pair<int, int>>>& adj) {
        vector<int> dist(26, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (node == dst)
                return currDist;

            if (currDist > dist[node])
                continue;

            for (auto& it : adj[node]) {
                int next = it.first;
                int wt = it.second;

                if (currDist + wt < dist[next]) {
                    dist[next] = currDist + wt;
                    pq.push({dist[next], next});
                }
            }
        }

        return -1;
    }

    long long minimumCost(string source, string target, vector<char>& original,
                          vector<char>& changed, vector<int>& cost) {

        if (source.size() != target.size())
            return -1;

        vector<vector<pair<int, int>>> adj(26);

        for (int i = 0; i < original.size(); i++) {
            adj[original[i] - 'a'].push_back({changed[i] - 'a', cost[i]});
        }

        long long totalCost = 0;

        for (int i = 0; i < source.size(); i++) {
            if (source[i] != target[i]) {
                int c = solve(source[i] - 'a', target[i] - 'a', adj);
                if (c == -1)
                    return -1;
                totalCost += c;
            }
        }

        return totalCost;
    }
};
