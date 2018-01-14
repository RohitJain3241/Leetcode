//This cade looks big but has repititions a lot!

class Solution {
    bool in_box(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if(matrix.size()==0)
            return res;
        int n = matrix.size(),m=matrix[0].size();
        vector<pair<int,int > > neigh = {{0,1},{1,0},{-1,0},{0,-1}};
        //We will make 2 matrices separately for both oceans
        //These 2 matrices will mark if this coordiante could meet corresponding oceans or not!
        vector<vector<int>> pac(n,vector<int>(m,0));
        vector<vector<int>> atl(n,vector<int>(m,0));
        
        //For Pacific Ocean initialization
        for(int i=0;i<n;i++)
            pac[i][0] = 1;
        //This is for the leftmost column
        for(int i=0;i<n;i++){
            queue<pair<int,int > > q;
            q.push(make_pair(i,0));
            while(!q.empty()){
                int x = q.front().first,y = q.front().second;
                q.pop();
                //For all its neighbours
                for(int i=0;i<4;i++){
                    int x_n = x+neigh[i].first, y_n = y+neigh[i].second;
                    //If it's value is equal or greater than previous value and should't be 1 in pac
                    if(in_box(x_n,y_n,n,m) && matrix[x_n][y_n]>=matrix[x][y] && pac[x_n][y_n]==0){
                        pac[x_n][y_n] = 1;
                        q.push(make_pair(x_n,y_n));
                    }
                }
            }
        }
        //This is for the topmost row
        for(int i=0;i<m;i++)
            pac[0][i] = 1;
        for(int i=0;i<m;i++){
            queue<pair<int,int > > q;
            q.push(make_pair(0,i));
            while(!q.empty()){
                int x = q.front().first,y = q.front().second;
                q.pop();
                //For all its neighbours
                for(int i=0;i<4;i++){
                    int x_n = x+neigh[i].first, y_n = y+neigh[i].second;
                    //If it's value is equal or greater than previous value and should't be 1 in pac
                    if(in_box(x_n,y_n,n,m) && matrix[x_n][y_n]>=matrix[x][y] && pac[x_n][y_n]==0){
                        pac[x_n][y_n] = 1;
                        q.push(make_pair(x_n,y_n));
                    }
                }
            }
        }
        
        //For Atlantic Ocean initialization
        for(int i=0;i<n;i++)
            atl[i][m-1] = 1;
        //This is for the rightmost column
        for(int i=0;i<n;i++){
            queue<pair<int,int > > q;
            q.push(make_pair(i,m-1));
            while(!q.empty()){
                int x = q.front().first,y = q.front().second;
                q.pop();
                //For all its neighbours
                for(int i=0;i<4;i++){
                    int x_n = x+neigh[i].first, y_n = y+neigh[i].second;
                    //If it's value is equal or greater than previous value and should't be 1 in pac
                    if(in_box(x_n,y_n,n,m) && matrix[x_n][y_n]>=matrix[x][y] && atl[x_n][y_n]==0){
                        atl[x_n][y_n] = 1;
                        q.push(make_pair(x_n,y_n));
                    }
                }
            }
        }
        //This is for the bottom row
        for(int i=0;i<m;i++)
            atl[n-1][i] = 1;
        for(int i=0;i<m;i++){
            queue<pair<int,int > > q;
            q.push(make_pair(n-1,i));
            while(!q.empty()){
                int x = q.front().first,y = q.front().second;
                q.pop();
                //For all its neighbours
                for(int i=0;i<4;i++){
                    int x_n = x+neigh[i].first, y_n = y+neigh[i].second;
                    //If it's value is equal or greater than previous value and should't be 1 in pac
                    if(in_box(x_n,y_n,n,m) && matrix[x_n][y_n]>=matrix[x][y] && atl[x_n][y_n]==0){
                        atl[x_n][y_n] = 1;
                        q.push(make_pair(x_n,y_n));
                    }
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pac[i][j] && atl[i][j])
                    res.push_back(make_pair(i,j));
            }
        }
        
        return res;
    }
};