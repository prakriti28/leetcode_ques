class Solution {

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        queue<int> q;
        vector<vector<int>> adj(numCourses);
        vector<int>inDegree(numCourses,0);

        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
             inDegree[it[0]]++;
        }

        // for (int i = 0; i < numCourses; i++) {
        //     for (auto it :adj[i]){
        //         inDegree[it]++;
        //     }
        // }
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                inDegree[it]--;
                if(inDegree[it]==0){
                    q.push(it);
                }
            }
        }
        if(topo.size()==numCourses) return topo;
        return {};
    }
};