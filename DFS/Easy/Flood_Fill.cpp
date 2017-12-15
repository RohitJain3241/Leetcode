class Solution {
    bool in_limit(int x,int y,int n,int m){
        return (x>=0 && y>=0 && x<n && y<m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        //There will be no 0 case for this problem!
        int n = image.size(),m = image[0].size();
        //Marking all the points as not visited at first
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<pair<int,int > > neigh = { {1,0}, {-1,0}, {0,1} , {0,-1} };
        //We will do dfs for this coordinate using stack
        //We will color the coordinate after all the neighbours are pushed into the stack
        stack<pair<int,int > > S;
        S.push(make_pair(sr,sc));
        visited[sr][sc] = 1;
        while(!S.empty()){
            int X = S.top().first,Y = S.top().second;
            S.pop();
            for(int i=0;i<4;i++){
                int x_n = X + neigh[i].first,y_n = Y + neigh[i].second;
                //last condition is to see if it is not visted again
                if(in_limit(x_n,y_n,n,m) && image[x_n][y_n]==image[X][Y] && !visited[x_n][y_n]){
                    S.push(make_pair(x_n,y_n));
                    visited[x_n][y_n] = 1;
                }
            }
            //this condition is lastly done so that comparison of colors from parent becomes easy
            image[X][Y] = newColor;
        }
        return image;
    }
};