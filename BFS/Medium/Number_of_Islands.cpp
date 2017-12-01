//Getting TLE exceeded!!
//Need help in this one!

class Solution {
    bool in_limit(int x,int y,int n,int m){
        if(x<n && y<m && x>=0 &&y>=0)
            return true;
        return false;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n==0)
            return 0;
        int m = grid[0].size();
        if(m==0)
            return 0;
        vector<pair<int,int > > neigh = {{0,1},{1,0},{-1,0},{0,-1}};
        //This is to mark the visited nodes till now!
        //Initially all are unvisited.
        vector<vector<int>> mark(n,vector<int>(m,0));
        //We will move forward and do bfs for each bfs we do counter++
        int counter=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //If it is land and not visited yet
                if(grid[i][j]=='1' && mark[i][j]==0){
                    counter++;
                    //Also see for all nearby neighbours
                    queue<pair<int,int> > q;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        //mark it as visited
                        int x=q.front().first,y=q.front().second;
                        q.pop();
                        mark[x][y] = 1;
                        //Now pushing them into q if they are 1 and not visited yet
                        for(int i=0;i<4;i++){
                            int x_n = x+neigh[i].first;
                            int y_n = y+neigh[i].second;
                            if(in_limit( x_n, y_n, n, m ) && grid[x_n][y_n]=='1' && !mark[x_n][y_n])
                                q.push(make_pair(x+neigh[i].first, y+neigh[i].second));  
                        }
                    }
                }
            }
        }
        return counter;
    }
};