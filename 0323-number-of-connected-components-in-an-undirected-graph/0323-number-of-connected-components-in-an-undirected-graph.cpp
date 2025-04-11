class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        queue<int> q;
        vector<int> adjList[n];
        int cnt = 0;

        for (int i = 0; i < edges.size(); i++) {
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                q.push(i);
                vis[i] = 1;
                cnt++;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto it : adjList[node]) {
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