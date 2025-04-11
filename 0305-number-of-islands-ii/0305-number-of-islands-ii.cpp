class DisjointSet {
    

public:
vector<int> size, parent;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u == up_v)
            return;
        if (up_u < up_v) {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        } else {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DisjointSet ds(m*n);
        vector<vector<int>>island(m,vector<int>(n,0));
        vector<int>ans;
        int cnt=0;

        for(auto it:positions){
            int row=it[0];
            int col=it[1];
            cout<<row<<col<<endl;
            if(island[row][col]){
                ans.push_back(cnt);
                continue;

            }
            island[row][col]=1;
            cnt++;

            vector<pair<int,int>>directions={{-1,0},{1,0},{0,1},{0,-1}};

            for(auto dir:directions){
                int nrow=dir.first+row;
                int ncol=dir.second+col;

                if(nrow>=0 and ncol>=0 and nrow<m and ncol<n
                and island[nrow][ncol]==1){
                    int nodeNo=row*n+col;
                    int adjNodeNo=nrow*n+ncol;
                    if(ds.findUPar(nodeNo)!=ds.findUPar(adjNodeNo)){
                        cnt--;
                        ds.unionBySize(nodeNo,adjNodeNo);
                    }

                }

            }
            ans.push_back(cnt);

        }

    return ans;
        
    }
};