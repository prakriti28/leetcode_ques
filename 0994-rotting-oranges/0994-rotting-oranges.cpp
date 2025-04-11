class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int fresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
                
            }
        }
        int t=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            int delrow[]={1,0,-1,0};
            int delcol[]={0,1,0,-1};
            t=max(t,tm);
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow<n and ncol<m and nrow>=0 and ncol>=0 and vis[nrow][ncol]!=2 and grid[nrow]
                [ncol]==1){
                    q.push({{nrow,ncol},tm+1});
                    fresh--;
                    vis[nrow][ncol]=2;
                }
            }
    }
        if(fresh==0){
           return t;
        }
        else{
            return -1;
        }
    }
};