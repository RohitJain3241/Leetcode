class Solution {
    bool in_box(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(),m=matrix[0].size();
        vector<pair<int,int > > neighbour = {{1,0},{0,1},{-1,0},{0,-1}};
        //We will go on to each cell and see if it has 0 , then do bfs with 1 as neighbour
        //if and only if d[i][j] value is greater than d[i][j] + 1
        vector<vector<int>> d(n,vector<int>(m,INT_MAX));
        //This is for moving and seeing for all 0 values!
        queue<pair<int,int> > q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    d[i][j] = 0;
                    q.push(make_pair(i,j));
                }
            }
        }
        
        //We could have done bfs if we had got 0 while traversing and update all the 1's in bfs
        //But it turns out to be slow
        //It is better to do bfs from all 0's first
        while(!q.empty()){
            int x = q.front().first,y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int x_n = x + neighbour[i].first, y_n = y + neighbour[i].second;
                if( in_box(x_n,y_n,n,m) && d[x_n][y_n] > d[x][y] + 1){
                    d[x_n][y_n] = d[x][y] + 1;
                    q.push(make_pair(x_n,y_n));
                }
            }
        }
        return d;
    }
};