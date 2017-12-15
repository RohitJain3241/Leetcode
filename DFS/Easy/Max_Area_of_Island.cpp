class Solution {
    bool in_limit(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        //Taking care for the zero case!
        if(n==0)
            return 0;
        int m = grid[0].size();
        vector<pair<int,int > > neigh = { {1,0}, {-1,0}, {0,1} , {0,-1} };
        int max_area=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    //Do not do anything and move forward
                }
                //If 1 is found 
                else{
                    //Make a new stack for dfs
                    stack<pair<int,int> > S;
                    S.push(make_pair(i,j));
                    grid[i][j] = 0;
                    //This will find the area of the temp_dfs
                    int temp_area = 0;
                    //Do dfs for this by seeing all the neighbours
                    while(!S.empty()){
                        //Pop the element and increase area
                        int X = S.top().first, Y = S.top().second;
                        S.pop();
                        temp_area++;
                        //Seeing for all its neighbours if it is not visited and '1'
                        for(int i=0;i<4;i++){
                            int x_n = X + neigh[i].first,y_n = Y + neigh[i].second;
                            if(in_limit(x_n,y_n,n,m) && grid[x_n][y_n]==1){
                                S.push(make_pair(x_n,y_n));
                                //this is equivalent to marking it visited
                                //This is done so that it is not double counted.
                                grid[x_n][y_n] = 0;
                            }
                        }
                    }
                    //Seeing if this dfs got us the max area of the island
                    if(max_area<temp_area)
                        max_area = temp_area;
                }
            }
        }
        return max_area;
    }
};