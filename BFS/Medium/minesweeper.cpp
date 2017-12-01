//Need help in this one  -  Don't know the reason for TLE


class Solution {
    bool in_box(int x,int y,int r,int c){
        if(x<r && y<c && x>=0 && y>=0)
            return true;
        else
            return false;
    }
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //If pressed mine
        if(board[click[0]][click[1]] == 'M'){
            board[click[0]][click[1]] = 'X';
            return board;
        }
        //If it is 'E', then do bfs for it 
        //where neighbours are the node with 'E'! 
        
        vector<pair<int,int > > neighbours = {{1,1},{1,0},{0,1},{1,-1},{0,-1},{-1,1},{-1,0},{-1,-1}};
        
        queue<pair<int,int > > q;
        q.push(make_pair(click[0],click[1]));
        while(!q.empty()){
            int x=q.front().first,y=q.front().second;
            q.pop();
            //See its all neighbours and mark it accordingly
            int mines = 0;
            for(int i=0;i<neighbours.size();i++){
                if(in_box(x+neighbours[i].first,y+neighbours[i].second,board.size(),board[0].size()) && board[x+neighbours[i].first][y+neighbours[i].second] == 'M')
                    mines++;
            }
            if(mines!=0)
                board[x][y] = mines + '0';
            else{
                board[x][y] = 'B';
                //Now pushing all the neighbours into queue if it is 'E' and not 'B'(which non-intendedly marks as visited)
                for(int i=0;i<neighbours.size();i++){
                    if(in_box(x+neighbours[i].first,y+neighbours[i].second,board.size(),board[0].size()) && board[x+neighbours[i].first][y+neighbours[i].second] == 'E')
                        q.push(make_pair( x+neighbours[i].first, y+neighbours[i].second ) );
                }
            }
        }
        return board;
    }
};