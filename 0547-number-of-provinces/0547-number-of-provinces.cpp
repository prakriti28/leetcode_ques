class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[200];

        for (int i = 0; i < n; i++) {
            for (int j = i; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1 and i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>vis(n,0);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                queue<int> q;
                q.push(i);
                cnt++;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : adj[node]) {
                        if (!vis[it]) {
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }

        return cnt;
    }
};