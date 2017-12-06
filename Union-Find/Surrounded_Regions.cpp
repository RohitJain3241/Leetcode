//This is a simple application of DFS or BFS from special points!

class Solution {
    bool on_board(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        int n = board.size(),m = board[0].size();
        vector<pair<int,int > > neigh = {{1,0},{0,1},{-1,0},{0,-1}};
        
        //Firstly we change all the boundary O's and corresponding BFS points to 'Z'
        queue<pair<int,int > > q;
        
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                board[i][0] = 'Z';
                q.push(make_pair(i,0));
            }
            if(board[i][m-1]=='O'){
                board[i][m-1] = 'Z';
                q.push(make_pair(i,m-1));
            }
        }
        
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                q.push(make_pair(0,i));
                board[0][i] = 'Z';
            }
            if(board[n-1][i]=='O'){
                q.push(make_pair(n-1,i));
                board[n-1][i] = 'Z';
            }
        }
        
        //There are 4 repititions at corners but wwould not change anything for us!
        while(!q.empty()){
            int x = q.front().first,y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x_n = x + neigh[i].first, y_n = y + neigh[i].second;
                if(on_board(x_n,y_n,n,m) && board[x_n][y_n]=='O'){
                    board[x_n][y_n] = 'Z';
                    q.push(make_pair(x_n,y_n));
                }
            }
        }
        
        //Again we traverse the board and mark all the Z's as O's and rest as X
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='Z')
                    board[i][j] = 'O';
                else
                    board[i][j] = 'X';
            }
        }
    }
};