class Solution {
private:

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>>& board){
    vis[row][col]=1;
    int n=board.size();
    int m=board[0].size();
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        if(nrow>=0 && ncol>=0 && nrow<n && ncol<m
       && board[nrow][ncol]=='O' && !vis[nrow][ncol]  )
        {
            dfs(nrow,ncol,vis,board);
        }

    }


}
public:
    void solve(vector<vector<char>>& board) {
    
        
        int n=board.size();
        if(n==0) return;
        int m=board[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int j=0;j<m;j++){
            if(!vis[0][j] and board[0][j]=='O'){
                dfs(0,j,vis,board);
            }
             if(!vis[n-1][j] and board[n-1][j]=='O'){
                dfs(n-1,j,vis,board);
            }
        }
        for(int i=0;i<n;i++){
             if(!vis[i][0] and board[i][0]=='O'){
                dfs(i,0,vis,board);
            }
             if(!vis[i][m-1] and board[i][m-1]=='O'){
                dfs(i,m-1,vis,board);
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

        
    }
};